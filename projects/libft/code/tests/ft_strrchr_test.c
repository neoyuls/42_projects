/* ************************************************************************** */
/*                                                                            */
/*   ft_strrchr_test.c                                                        */
/*                                                                            */
/*   Simple harness: compares ft_strrchr against the libc reference           */
/*   strrchr() over a fixed table of cases and reports PASS/FAIL.             */
/*                                                                            */
/*   Build & run:                                                             */
/*     cc -Wall -Wextra -Werror -Iincludes tests/ft_strrchr_test.c \          */
/*        srcs/ft_strrchr.c srcs/ft_strlen.c -o ft_strrchr_test               */
/*     ./ft_strrchr_test                                                      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

/*
** Returns 1 when both pointers are NULL, or when both point at the same
** offset inside s. Comparing offsets (not just contents) is what proves
** ft_strrchr returned the *last* occurrence and not, say, ft_strchr's one.
*/
static int	same_result(const char *s, const char *got, const char *exp)
{
	if (got == NULL || exp == NULL)
		return (got == exp);
	return (got - s == exp - s);
}

static void	print_char(int c)
{
	if (c == '\0')
		printf("'\\0'");
	else
		printf("'%c'", c);
}

static int	run_case(const char *label, const char *s, int c)
{
	char	*got;
	char	*exp;
	int		ok;

	got = ft_strrchr(s, c);
	exp = strrchr(s, c);
	ok = same_result(s, got, exp);
	printf("%-4s %-22s s=\"%s\" c=", ok ? "PASS" : "FAIL", label, s);
	print_char(c);
	if (!ok)
		printf("   -> got %s, expected %s",
			got ? "a match" : "NULL", exp ? "a match" : "NULL");
	printf("\n");
	return (ok);
}

int	main(void)
{
	static const char	*strs[] = {
		"",
		"a",
		"abcabc",
		"hello world",
		"aaaa",
		"42 Malaga",
		"\xff\x80\x7f"
	};
	static const int	chars[] = {'a', 'b', 'c', 'z', '\0', ' ', '4', 0xff};
	int					fails;
	int					total;
	size_t				i;
	size_t				j;

	fails = 0;
	total = 0;
	i = 0;
	while (i < sizeof(strs) / sizeof(strs[0]))
	{
		j = 0;
		while (j < sizeof(chars) / sizeof(chars[0]))
		{
			total++;
			if (!run_case("strrchr", strs[i], chars[j]))
				fails++;
			j++;
		}
		i++;
	}
	printf("\n%d/%d passed, %d failed\n", total - fails, total, fails);
	return (fails != 0);
}
