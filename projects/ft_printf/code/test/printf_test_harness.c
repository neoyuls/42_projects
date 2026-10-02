/* ************************************************************************** */
/*                                                                            */
/*   printf_test_harness.c                                                    */
/*                                                                            */
/*   Compares ft_printf against the system printf():                          */
/*     - the bytes written to stdout                                          */
/*     - the value returned                                                  */
/*                                                                            */
/*   Build (once the library sources compile):                                */
/*                                                                            */
/*     cc -Wall -Wextra -Werror -I includes printf_test_harness.c \           */
/*        srcs/ft_printf.c srcs/putnumber.c srcs/putpointer.c \               */
/*        srcs/putstring.c -o printf_test                                     */
/*     ./printf_test                                                          */
/*                                                                            */
/*   Each call is run with fd 1 redirected to a scratch file so its exact     */
/*   output can be captured and diffed byte-for-byte, NUL bytes included.     */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#define CAP 8192

static int	g_total;
static int	g_fail;

/*
** Run `call` with stdout redirected to a scratch file.  Captures the raw
** bytes into dst (NUL-terminated only for display), the byte count into
** olen, and the call's return value into retval.
*/
#define CAPTURE(dst, retval, olen, call) do {                        \
	fflush(stdout);                                               \
	int _saved = dup(STDOUT_FILENO);                              \
	char _path[] = "/tmp/printf_harness_XXXXXX";                  \
	int _fd = mkstemp(_path);                                     \
	unlink(_path);                                                \
	dup2(_fd, STDOUT_FILENO);                                     \
	(retval) = (call);                                            \
	fflush(stdout);                                               \
	off_t _end = lseek(_fd, 0, SEEK_END);                         \
	lseek(_fd, 0, SEEK_SET);                                      \
	if (_end < 0)                                                 \
		_end = 0;                                                 \
	if (_end > CAP - 1)                                           \
		_end = CAP - 1;                                           \
	ssize_t _got = read(_fd, (dst), (size_t)_end);                \
	if (_got < 0)                                                 \
		_got = 0;                                                 \
	(dst)[_got] = '\0';                                           \
	(olen) = (int)_got;                                           \
	close(_fd);                                                   \
	dup2(_saved, STDOUT_FILENO);                                  \
	close(_saved);                                                \
} while (0)

/* Render a byte string safely: control bytes become escapes. */
static void	escape(const char *s, int len, char *out, size_t outsz)
{
	const char	*hex = "0123456789abcdef";
	size_t		j;
	int			i;
	unsigned char	c;

	j = 0;
	i = 0;
	while (i < len && j + 5 < outsz)
	{
		c = (unsigned char)s[i++];
		if (c == '\n')
			out[j++] = '\\', out[j++] = 'n';
		else if (c == '\t')
			out[j++] = '\\', out[j++] = 't';
		else if (c == '\\')
			out[j++] = '\\', out[j++] = '\\';
		else if (c >= 32 && c < 127)
			out[j++] = (char)c;
		else
			out[j++] = '\\', out[j++] = 'x',
			out[j++] = hex[c >> 4], out[j++] = hex[c & 15];
	}
	out[j] = '\0';
}

static void	report(const char *label, const char *real, int real_ret,
		int real_len, const char *ours, int our_ret, int our_len)
{
	int		ok;
	char	er[4200];
	char	eo[4200];

	ok = (real_ret == our_ret)
		&& (real_len == our_len)
		&& (memcmp(real, ours, (size_t)real_len) == 0);
	g_total++;
	if (!ok)
		g_fail++;
	escape(real, real_len, er, sizeof er);
	escape(ours, our_len, eo, sizeof eo);
	printf("%-24s %s\n", label, ok ? "PASS" : "FAIL");
	if (!ok)
	{
		printf("    printf    : \"%s\"  ret=%d\n", er, real_ret);
		printf("    ft_printf : \"%s\"  ret=%d\n", eo, our_ret);
	}
}

#define CHECK(label, ...) do {                                       \
	char _a[CAP];                                                    \
	char _b[CAP];                                                    \
	int _ra, _rb, _la, _lb;                                          \
	CAPTURE(_a, _ra, _la, printf(__VA_ARGS__));                      \
	CAPTURE(_b, _rb, _lb, ft_printf(__VA_ARGS__));                   \
	report((label), _a, _ra, _la, _b, _rb, _lb);                     \
} while (0)

/*
** Undefined specifiers: behaviour is not defined by C, so there is nothing
** meaningful to diff against printf.  The only real requirements are that
** ft_printf does not crash, does not read out of bounds, and does not loop
** forever.  A hang here means a conversion branch is not advancing.
*/
static void	robust(const char *label, const char *fmt)
{
	int	ret;

	printf("%-24s ", label);
	fflush(stdout);
	ret = ft_printf(fmt);
	printf("  -> returned %d\n", ret);
}

int	main(void)
{
	int		x = 42;
	char		*np = NULL;
	void		*zp = NULL;

	/* Keep our own reporting and ft_printf's raw writes in order. */
	setvbuf(stdout, NULL, _IONBF, 0);

	puts("=== compared against printf ===");

	/* literals and % */
	CHECK("plain text", "hello, world");
	CHECK("empty format", "");
	CHECK("percent literal", "100%% done");
	CHECK("bare percent", "%%");

	/* %c */
	CHECK("%c letter", "[%c]", 'A');
	CHECK("%c NUL", "[%c]", 0);
	CHECK("%c x3", "%c%c%c", 'x', 'y', 'z');

	/* %s */
	CHECK("%s basic", "[%s]", "hello");
	CHECK("%s empty", "[%s]", "");
	CHECK("%s NULL", "[%s]", np);

	/* %d / %i */
	CHECK("%d zero", "%d", 0);
	CHECK("%d positive", "%d", 42);
	CHECK("%d negative", "%d", -42);
	CHECK("%i negative", "%i", -2147483647);
	CHECK("%d INT_MAX", "%d", INT_MAX);
	CHECK("%d INT_MIN", "%d", INT_MIN);

	/* %u */
	CHECK("%u zero", "%u", 0u);
	CHECK("%u small", "%u", 300u);
	CHECK("%u UINT_MAX", "%u", UINT_MAX);

	/* %x / %X */
	CHECK("%x zero", "%x", 0u);
	CHECK("%x small", "%x", 0x2au);
	CHECK("%x DEADBEEF", "%x", 0xdeadbeefu);
	CHECK("%X ABCDEF", "%X", 0xabcdefu);
	CHECK("%x UINT_MAX", "%x", UINT_MAX);
	CHECK("%x -1 as unsigned", "%x", (unsigned int)-1);

	/* %p */
	CHECK("%p object", "%p", (void *)&x);
	CHECK("%p NULL", "%p", zp);

	/* combinations, to exercise return-value accumulation */
	CHECK("mixed", "[%d|%s|%c|%x|%%]", -7, "mix", 'Z', 0x1fu);
	CHECK("many ints", "%d %d %d %d", 1, -2, 3, -4);
	CHECK("no specifiers", "just text");

	puts("\n=== robustness (undefined specifiers, not compared) ===");
	robust("invalid %y", "A[%y]B");
	robust("invalid %z", "A[%z]B");
	robust("invalid %q", "A[%q]B");
	robust("trailing percent", "trailing%");
	robust("percent then NUL", "%");

	printf("\n=== %d/%d passed, %d failed ===\n",
		g_total - g_fail, g_total, g_fail);
	return (g_fail != 0);
}
