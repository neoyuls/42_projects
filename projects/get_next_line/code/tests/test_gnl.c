/* ************************************************************************** */
/*                                                                            */
/*   test_gnl.c - a self-contained diagnostic harness for get_next_line.       */
/*                                                                            */
/*   Each case runs in a forked child, so a segfault / abort / ASan error in   */
/*   get_next_line only fails that one case and the run continues. The child   */
/*   prints the diff, the parent prints ok / FAIL / CRASH per case.            */
/*                                                                            */
/*   Build: see tests/run_tests.sh                                              */
/* ************************************************************************** */

#define _GNU_SOURCE
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include "get_next_line.h"

static int	g_fail;

/* ------------------------------------------------------------------ output */

static void	print_escaped(const char *label, const char *s)
{
	size_t	i;

	fprintf(stderr, "        %s: \"", label);
	if (!s)
		fprintf(stderr, "(null)");
	else
	{
		for (i = 0; s[i]; i++)
		{
			if (s[i] == '\n')
				fputs("\\n", stderr);
			else if (s[i] == '\r')
				fputs("\\r", stderr);
			else if (s[i] == '\t')
				fputs("\\t", stderr);
			else if ((unsigned char)s[i] < 32)
				fprintf(stderr, "\\x%02x", (unsigned char)s[i]);
			else
				fputc(s[i], stderr);
		}
	}
	fprintf(stderr, "\"\n");
}

static void	fail(const char *name, const char *what)
{
	g_fail++;
	fprintf(stderr, "  [FAIL] %s: %s\n", name, what);
}

/* --------------------------------------------------------------- reference  */

/* Reference lines via POSIX getline(): delimiters match the GNL subject. */
static char	**ref_collect_file(const char *path, int *count)
{
	FILE	*f;
	char	**arr;
	char	*line;
	size_t	cap_line;
	ssize_t	r;
	int		n;
	int		cap;

	f = fopen(path, "r");
	if (!f)
	{
		perror("fopen");
		exit(2);
	}
	arr = NULL;
	line = NULL;
	cap_line = 0;
	n = 0;
	cap = 0;
	while ((r = getline(&line, &cap_line, f)) != -1)
	{
		if (n == cap)
		{
			cap = cap ? cap * 2 : 8;
			arr = realloc(arr, sizeof(char *) * cap);
		}
		arr[n] = strdup(line);
		n++;
	}
	free(line);
	fclose(f);
	*count = n;
	return (arr);
}

static char	**gnl_collect(int fd, int *count, int *overflow)
{
	char	**arr;
	char	*line;
	int		n;
	int		cap;

	arr = NULL;
	n = 0;
	cap = 0;
	*overflow = 0;
	while (1)
	{
		if (n > 200000)
		{
			*overflow = 1;
			break ;
		}
		line = get_next_line(fd);
		if (!line)
			break ;
		if (n == cap)
		{
			cap = cap ? cap * 2 : 8;
			arr = realloc(arr, sizeof(char *) * cap);
		}
		arr[n] = line;
		n++;
	}
	*count = n;
	return (arr);
}

static void	free_lines(char **arr, int n)
{
	int	i;

	i = 0;
	while (i < n)
		free(arr[i++]);
	free(arr);
}

static void	compare(const char *name, char **got, int gcount,
				char **ref, int rcount)
{
	char	buf[160];
	int		n;
	int		i;

	if (gcount != rcount)
	{
		snprintf(buf, sizeof(buf), "line count: got %d, expected %d",
			gcount, rcount);
		fail(name, buf);
	}
	n = gcount < rcount ? gcount : rcount;
	i = 0;
	while (i < n)
	{
		if (strcmp(got[i], ref[i]) != 0)
		{
			snprintf(buf, sizeof(buf), "line %d differs", i);
			fail(name, buf);
			print_escaped("got     ", got[i]);
			print_escaped("expected", ref[i]);
		}
		i++;
	}
	i = n;
	while (i < gcount)
		fail(name, "(extra line returned)");
	i = n;
	while (i < rcount)
		fail(name, "(line missing)");
}

/* ------------------------------------------------------------------- cases */

struct s_content_case
{
	const char	*name;
	const char	*content;
};

static void	make_file(char *path_template, const char *content, size_t len)
{
	int	fd;

	fd = mkstemp(path_template);
	if (fd < 0)
	{
		perror("mkstemp");
		exit(2);
	}
	if (len && write(fd, content, len) != (ssize_t)len)
	{
		perror("write");
		exit(2);
	}
	close(fd);
}

static void	run_case_body(const char *name, const char *content)
{
	char	path[] = "/tmp/gnl_case_XXXXXX";
	char	**ref;
	char	**got;
	char	*extra;
	int		rcount;
	int		gcount;
	int		overflow;
	int		fd;

	make_file(path, content, strlen(content));
	ref = ref_collect_file(path, &rcount);
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		exit(2);
	}
	got = gnl_collect(fd, &gcount, &overflow);
	if (overflow)
		fail(name, "never returned NULL (infinite-loop guard hit)");
	compare(name, got, gcount, ref, rcount);
	extra = get_next_line(fd);
	if (extra)
	{
		fail(name, "returned a line after EOF");
		print_escaped("extra", extra);
		free(extra);
	}
	extra = get_next_line(fd);
	if (extra)
	{
		fail(name, "second call after EOF returned a line");
		free(extra);
	}
	free_lines(got, gcount);
	free_lines(ref, rcount);
	close(fd);
	unlink(path);
}

/* Interleaved reads from three fds at once (the mandatory bonus check). */
static void	run_multi_fd_body(void)
{
	const char	*contents[3] = {"aaa\nbb\nccccccc\n", "1\n2\n3", "\n\nx\n"};
	char		paths[3][32] = {"/tmp/gnl_m0_XXXXXX", "/tmp/gnl_m1_XXXXXX",
					"/tmp/gnl_m2_XXXXXX"};
	char		**ref[3];
	char		*line;
	int			rcount[3];
	int			fds[3];
	int			maxc;
	int			i;
	int			f;

	f = 0;
	maxc = 0;
	while (f < 3)
	{
		make_file(paths[f], contents[f], strlen(contents[f]));
		ref[f] = ref_collect_file(paths[f], &rcount[f]);
		if (rcount[f] > maxc)
			maxc = rcount[f];
		fds[f] = open(paths[f], O_RDONLY);
		if (fds[f] < 0)
		{
			perror("open");
			exit(2);
		}
		f++;
	}
	i = 0;
	while (i < maxc)
	{
		f = 0;
		while (f < 3)
		{
			if (i < rcount[f])
			{
				line = get_next_line(fds[f]);
				if (!line)
					fail("multi-fd", "premature NULL while other fds pending");
				else
				{
					if (strcmp(line, ref[f][i]) != 0)
					{
						fprintf(stderr, "  [FAIL] multi-fd: fd %d line %d\n",
							f, i);
						print_escaped("got     ", line);
						print_escaped("expected", ref[f][i]);
						g_fail++;
					}
					free(line);
				}
			}
			f++;
		}
		i++;
	}
	f = 0;
	while (f < 3)
	{
		line = get_next_line(fds[f]);
		if (line)
		{
			fail("multi-fd", "line after EOF");
			free(line);
		}
		free_lines(ref[f], rcount[f]);
		close(fds[f]);
		unlink(paths[f]);
		f++;
	}
}

static void	run_invalid_fd_body(void)
{
	char	path[] = "/tmp/gnl_inv_XXXXXX";
	char	*line;
	int		fd;

	line = get_next_line(-1);
	if (line)
	{
		fail("invalid-fd", "fd -1 returned non-NULL");
		free(line);
	}
	line = get_next_line(999999);
	if (line)
	{
		fail("invalid-fd", "unopened fd returned non-NULL");
		free(line);
	}
	make_file(path, "hello\n", 6);
	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	if (!line || strcmp(line, "hello\n") != 0)
	{
		fail("invalid-fd", "valid read broken after invalid fd calls");
		print_escaped("got", line);
	}
	free(line);
	line = get_next_line(fd);
	if (line)
	{
		fail("invalid-fd", "expected NULL after last line");
		free(line);
	}
	close(fd);
	unlink(path);
}

/* ------------------------------------------------------------------ runner */

typedef void	(*t_worker)(void *arg);

static void	run_protected(const char *name, t_worker fn, void *arg)
{
	pid_t	pid;
	int		status;

	printf("  case: %s\n", name);
	fflush(stdout);
	fflush(stderr);
	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		exit(2);
	}
	if (pid == 0)
	{
		fn(arg);
		fflush(stdout);
		fflush(stderr);
		exit(g_fail ? 1 : 0);
	}
	waitpid(pid, &status, 0);
	if (WIFSIGNALED(status))
	{
		g_fail++;
		fprintf(stderr, "  [CRASH] %s: killed by signal %d\n",
			name, WTERMSIG(status));
	}
	else if (!WIFEXITED(status) || WEXITSTATUS(status) != 0)
		g_fail++;
	else
		printf("    ok\n");
	fflush(stdout);
}

static void	content_worker(void *arg)
{
	const struct s_content_case	*c;

	c = arg;
	run_case_body(c->name, c->content);
}

static void	multi_worker(void *arg)
{
	(void)arg;
	run_multi_fd_body();
}

static void	invalid_worker(void *arg)
{
	(void)arg;
	run_invalid_fd_body();
}

static void	run_content(const char *name, const char *content)
{
	struct s_content_case	c;

	c.name = name;
	c.content = content;
	run_protected(name, content_worker, &c);
}

static char	*rep(char ch, size_t n, int newline)
{
	char	*s;
	size_t	i;

	s = malloc(n + 2);
	if (!s)
		exit(2);
	i = 0;
	while (i < n)
		s[i++] = ch;
	if (newline)
		s[n++] = '\n';
	s[n] = '\0';
	return (s);
}

static char	*many_lines(int n)
{
	char	*s;
	char	tmp[32];
	int		i;

	s = malloc((size_t)n * 32 + 1);
	if (!s)
		exit(2);
	s[0] = '\0';
	i = 0;
	while (i < n)
	{
		snprintf(tmp, sizeof(tmp), "line %03d\n", i);
		strcat(s, tmp);
		i++;
	}
	return (s);
}

int	main(void)
{
	char	*longline;
	char	*exact;
	char	*longlast;
	char	*many;

	setvbuf(stdout, NULL, _IONBF, 0);
	printf("=== get_next_line harness (BUFFER_SIZE=%d, %s) ===\n",
		BUFFER_SIZE,
#ifdef __SANITIZE_ADDRESS__
		"asan"
#else
		"sanity"
#endif
		);

	run_content("empty file", "");
	run_content("only newline", "\n");
	run_content("single line + nl", "hello\n");
	run_content("single line no nl", "hello");
	run_content("two lines + nl", "hello\nworld\n");
	run_content("two lines, last no nl", "hello\nworld");
	run_content("blank lines", "\n\n\n");
	run_content("trailing blank lines", "a\n\n\n");
	run_content("crlf", "hello\r\nworld\r\n");
	run_content("single char no nl", "x");
	run_content("single char + nl", "x\n");

	longline = rep('a', 5000, 1);
	exact = rep('b', BUFFER_SIZE, 1);
	longlast = rep('z', 1000, 0);
	many = many_lines(300);
	run_content("long line 5000 + nl", longline);
	run_content("exactly BUFFER_SIZE + nl", exact);
	run_content("long last line, no nl", longlast);
	run_content("300 short lines", many);
	free(longline);
	free(exact);
	free(longlast);
	free(many);

	run_protected("multi-fd interleaved", multi_worker, NULL);
	run_protected("invalid fds", invalid_worker, NULL);

	printf("=== done: %s ===\n", g_fail ? "FAILURES FOUND" : "all cases passed");
	return (g_fail ? 1 : 0);
}
