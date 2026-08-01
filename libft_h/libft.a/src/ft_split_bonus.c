/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neoyuls <neoyuls@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 20:31:57 by neoyuls           #+#    #+#             */
/*   Updated: 2026/08/01 12:55:45 by neoyuls          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
// bit scared of this one...
static char	**fill(char **arr, const char *s, char c)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			arr[j][k] = '\0';
			k = 0;
			j++;
			arr[j][k] = c;
		}
		else
			arr[j][k] = s[i];
		i++;
		k++;
	}
	return (arr);
}
static char	**allocate(const char *s, int ccount)
{
	int		i;
	int		j;
	char	**arr;

	i = 0;
	j = ft_strlen((char *)s);
	arr = malloc(sizeof(char *) * (ccount + 1));
	while (i <= (ccount + 1))
	{
		arr[i] = malloc(sizeof(char) * j);
		i++;
	}
	return (arr);
}
char	**ft_split(const char *s, char c)
{
	char 	**strings;
	int		i;
	int		ccount;

	i = 0;
	ccount = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			ccount++;
		}
		i++;
	}
	strings = allocate(s, ccount);
	strings = fill(strings, s, c);
	return (strings);
}
/* ATTEMPT 1, going to retry to build from 0
static char	**ft_allocate(char const *s, char c)
{
	char	**sa;
	int		i;
	int		j;
	int		k;
	int		ccount;

	i = 0;
	j = 0;
	k = 0;
	ccount = 0;
	while (s[i])
	{
		if (s[i] == c)
			ccount++;
		i++;
	}
	sa = (char **)malloc((2 + ccount) * sizeof(char *));
	if (sa == NULL)
		return (NULL);
	i = 0;
	while (s[j])
	{
		k++;
		if (s[j] == c)
		{
			sa[i] = (char *)malloc(sizeof(char) * (k + 1));
			if (sa[i] == NULL)
				return (NULL);
			i++;
			k = 0;
		}
		j++;
	}
	sa[i] = (char *)malloc(sizeof(char) * (k + 1));
	return (sa);
}

char	**ft_split(char const *s, char c)
{
	char	**sa;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	sa = ft_allocate(s, c);
	if (sa == NULL)
	{
		return (NULL);
	}
	while (s[k])
	{
		sa[i][j] = s[k];
		if (s[k] == c)
		{
			sa[i][j] = '\0';
			i++;
			j = 0;
		}
		k++;
		j++;
	}
	return (sa);
}
*/
#include <stdio.h>

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		write (2, "error\n", 6);
		return (1);
	}
	char	**sa = ft_split(av[1], av[2][0]);
	printf("%s\n", sa[0]);
	while (*sa)
	{
		printf("Result: %s\n", *sa);
		write (1, "hi\n", 3);
		sa++;
	}
	free(sa);
}
