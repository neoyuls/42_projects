/* ************************************************************************** */
/*                                                                            */
/*   count_word_test.c                                                        */
/*                                                                            */
/*   Unit test for the counting pass of ft_split. The point is to test the    */
/*   word-counting loop ON ITS OWN, on a table of inputs, before trusting it  */
/*   inside ft_split. A number on a screen beats a guess.                     */
/*                                                                            */
/*   Build and run (no libft needed, this file is self-contained):            */
/*                                                                            */
/*     cc -Wall -Wextra -Werror -g tests/count_word_test.c -o /tmp/cwt        */
/*     /tmp/cwt                                                               */
/*                                                                            */
/*   Run it AGAIN with AddressSanitizer. The table only tells you whether the */
/*   answers are right; ASan tells you whether you read memory you do not     */
/*   own, which the table can never show you:                                 */
/*                                                                            */
/*     cc -Wall -Wextra -Werror -g -fsanitize=address \                       */
/*        tests/count_word_test.c -o /tmp/cwt_asan                            */
/*     /tmp/cwt_asan                                                          */
/*                                                                            */
/*   Note: ASan aborts the process on the first invalid read, so the empty    */
/*   string case is deliberately LAST in the table - that way you still see   */
/*   the rest of the results before it dies.                                  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/*
** ---------------------------------------------------------------------------
** CODE UNDER TEST
** ---------------------------------------------------------------------------
** This is the counting loop as it stands right now, copied here verbatim so
** it can be edited and re-run in isolation. Fix it HERE first; when the table
** is all green, copy it back into src/ft_split.c.
**
** (Yes, this is a copy, and copies drift. That is the price of unit-testing a
** static helper in C. The alternative - testing only through ft_split - means
** a bad count and a bad malloc look like the same bug.)
*/

static unsigned int	count_words(char const *s, char c)
{
	unsigned int	i;
	unsigned int	count;

	i = 0;
	count = 0;
	if (s[i] != c)
	{
		i++;
		count++;
	}
	while (s[i])
	{
		if (s[i] != c && s[i - 1] == c)
			count++;
		i++;
	}
	return (count);
}

/*
** ---------------------------------------------------------------------------
** THE TABLE
** ---------------------------------------------------------------------------
** expected = the number of words a correct ft_split must find.
** Order matters: keep the failing/deadly cases last so ASan lets the rest run.
*/

typedef struct s_case
{
	char const		*s;
	char			c;
	unsigned int	expected;
}	t_case;

int	main(void)
{
	static const t_case	cases[] = {
	{"a", ',', 1},
	{",", ',', 0},
	{",a", ',', 1},
	{"a,", ',', 1},
	{"a,,b", ',', 2},
	{"a,b,c", ',', 3},
	{"ab,cd", ',', 2},
	{"a,,,b", ',', 2},
	{"ab", ',', 1},
	{",,,,", ',', 0},
	{"a,b,,", ',', 2},
	{"a,bb,ccc,dddd", ',', 4},
	{"  a  b  ", ' ', 2},
	{"hello world", ' ', 2},
	{"   ", ' ', 0},
	{"a", 'a', 0},
	{"aa", 'a', 0},
	{"bab", 'a', 2},
	{"", ',', 0},
	};
	unsigned int		n;
	unsigned int		k;
	unsigned int		got;
	unsigned int		failed;

	n = (unsigned int)(sizeof(cases) / sizeof(cases[0]));
	k = 0;
	failed = 0;
	while (k < n)
	{
		got = count_words(cases[k].s, cases[k].c);
		if (got == cases[k].expected)
			printf("  ok   \"%s\" c='%c'  -> %u\n",
				cases[k].s, cases[k].c, got);
		else
		{
			printf("FAIL   \"%s\" c='%c'  -> got %u, expected %u\n",
				cases[k].s, cases[k].c, got, cases[k].expected);
			failed++;
		}
		k++;
	}
	printf("\n%u passed, %u failed\n", n - failed, failed);
	if (failed)
		return (1);
	return (0);
}
