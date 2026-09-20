#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size);

static size_t	ref_strlcat(char *dst, const char *src, size_t siz)
{
	char		*d = dst;
	const char	*s = src;
	size_t		n = siz;
	size_t		dlen;

	while (n-- != 0 && *d != '\0')
		d++;
	dlen = (size_t)(d - dst);
	n = siz - dlen;
	if (n == 0)
		return (dlen + strlen(s));
	while (*s != '\0')
	{
		if (n != 1)
		{
			*d++ = *s;
			n--;
		}
		s++;
	}
	*d = '\0';
	return (dlen + (size_t)(s - src));
}

#define CANARY 0xCC
#define MAXALLOC 24

struct s_case {
	const char	*name;
	const char	*dst_bytes;
	size_t		dst_len;
	size_t		alloc;
	size_t		size;
	const char	*src;
};

static void	dump(const char *label, unsigned char *b, size_t n)
{
	size_t i;
	printf("      %s: [", label);
	for (i = 0; i < n; i++)
		printf("%s%02x", i ? " " : "", b[i]);
	printf("]\n");
}

static void	run_one(struct s_case *c, int use_ft, unsigned char *out, size_t *ret)
{
	unsigned char	*dst;
	size_t			r;

	dst = malloc(c->alloc);
	if (!dst)
		_exit(9);
	memset(dst, CANARY, c->alloc);
	memcpy(dst, c->dst_bytes, c->dst_len);
	if (use_ft)
		r = ft_strlcat((char *)dst, c->src, c->size);
	else
		r = ref_strlcat((char *)dst, c->src, c->size);
	*ret = r;
	memcpy(out, dst, c->alloc);
	free(dst);
}

static int	run_child(struct s_case *c, int use_ft, unsigned char *out, size_t *ret)
{
	pid_t	pid;
	int		st;
	int		pipefd[2];
	unsigned char	buf[MAXALLOC];
	size_t	r = 0;

	memset(buf, 0, sizeof(buf));
	if (pipe(pipefd) != 0)
		_exit(8);
	pid = fork();
	if (pid == 0)
	{
		close(pipefd[0]);
		run_one(c, use_ft, buf, &r);
		if (write(pipefd[1], &r, sizeof(r)) != (ssize_t)sizeof(r))
			_exit(7);
		if (write(pipefd[1], buf, MAXALLOC) != MAXALLOC)
			_exit(7);
		close(pipefd[1]);
		_exit(0);
	}
	close(pipefd[1]);
	waitpid(pid, &st, 0);
	if (!WIFEXITED(st) || WEXITSTATUS(st) != 0)
	{
		close(pipefd[0]);
		return (WIFSIGNALED(st) ? -WTERMSIG(st) : -(WEXITSTATUS(st) + 100));
	}
	if (read(pipefd[0], &r, sizeof(r)) != (ssize_t)sizeof(r)
		|| read(pipefd[0], buf, MAXALLOC) != MAXALLOC)
	{
		close(pipefd[0]);
		return (-99);
	}
	close(pipefd[0]);
	*ret = r;
	memcpy(out, buf, MAXALLOC);
	return (0);
}

int	main(void)
{
	static struct s_case	cases[] = {
		{"normal fit",           "abc\0",  4, 16, 16, "def"},
		{"exact fit (size=7)",   "abc\0",  4, 16,  7, "def"},
		{"one byte short",       "abc\0",  4, 16,  6, "def"},
		{"nothing fits (size=4)","abc\0",  4, 16,  4, "def"},
		{"size == dstlen",       "abc\0",  4, 16,  3, "def"},
		{"size < dstlen",        "abc\0",  4, 16,  2, "def"},
		{"size == 0",            "abc\0",  4, 16,  0, "def"},
		{"size == 0, empty src", "abc\0",  4, 16,  0, ""},
		{"size == 1, empty dst", "\0",     1, 16,  1, "def"},
		{"size == 1, full dst",  "abc\0",  4, 16,  1, "def"},
		{"empty src, fits",      "abc\0",  4, 16, 16, ""},
		{"empty src, size<len",  "abc\0",  4, 16,  2, ""},
		{"empty dst",            "\0",     1, 16, 16, "hello"},
		{"empty src, size 1",    "abc\0",  4, 16,  1, ""},
		{"long truncation",      "hello\0",6, 16,  8, "world!!!"},
		{"unterminated d, size==alloc", "abcdef", 6, 6, 6, "xyz"},
		{"unterminated d, size<alloc",  "abcdef", 6, 9, 4, "xyz"},
		{"unterminated d, size=1",      "abcdef", 6, 9, 1, "xyz"},
		{"canary after size",    "abc\0",  4, 16,  3, "de"},
		{"size 0, unterminated", "abcdef", 6, 6,  0, "xyz"},
		{NULL, NULL, 0, 0, 0, NULL}
	};
	size_t	i;
	int		fails = 0;

	for (i = 0; cases[i].name; i++)
	{
		unsigned char	bf[MAXALLOC], br[MAXALLOC];
		size_t			rf = 0, rr = 0;
		int				sf, sr;

		sr = run_child(&cases[i], 0, br, &rr);
		sf = run_child(&cases[i], 1, bf, &rf);
		printf("%-30s size=%-2zu strlen(src)=%zu\n", cases[i].name,
			cases[i].size, strlen(cases[i].src));
		if (sr != 0)
		{
			printf("      reference failed (%d) - case skipped\n\n", sr);
			continue;
		}
		if (sf != 0)
		{
			printf("      *** ft_strlcat CRASHED/FAILED (%d) = out-of-bounds access\n\n", sf);
			fails++;
			continue;
		}
		if (rf != rr)
		{
			printf("      *** return value: ft=%zu  ref=%zu\n", rf, rr);
			fails++;
		}
		if (memcmp(bf, br, MAXALLOC) != 0)
		{
			printf("      *** destination bytes differ\n");
			dump("ft ", bf, 12);
			dump("ref", br, 12);
			fails++;
		}
		if (rf == rr && memcmp(bf, br, MAXALLOC) == 0)
			printf("      ok (ret=%zu)\n", rf);
		printf("\n");
	}
	printf("TOTAL FAILING CASES: %d\n", fails);
	return (fails != 0);
}
