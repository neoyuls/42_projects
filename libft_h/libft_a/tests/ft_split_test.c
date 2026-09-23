/* ************************************************************************** */
/*                                                                            */
/*   ft_split_test.c                                                          */
/*                                                                            */
/*                                                                            */
/*   Harness for ft_split: prints every word for a string and delimiter.      */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	count_words(char const *s, char c)
{
	unsigned int count; 
	unsigned int i; 


	i = 0;
	count = 0;
	if (s[i] != c && s[i] != '\0')
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

int	main(int ac, char **av)
{
	if (ac > 3)
	{
		write(2, "Too many arguments.\n", 20);
		return (1);
	}
	if (ac < 3)
	{
		write(2, "Too few arguments.\n", 18);
		return (1);
	}
	
	int i = count_words(av[1], av[2][0]);
	char **strarr = ft_split(av[1], av[2][0]);
	for (int j = 0; j < i; j++)
	{
		write(1, strarr[j], ft_strlen(strarr[j]));
		write(1, "\n", 1);
	}
	return (0);
}
