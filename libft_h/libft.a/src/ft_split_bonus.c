/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neoyuls <neoyuls@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 20:31:57 by neoyuls           #+#    #+#             */
/*   Updated: 2026/07/29 12:18:12 by neoyuls          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
// bit scared of this one...
static char	**ft_allocate(char const *s, char c)
{
	char	**sa;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	sa = NULL;
	while (s[i])
	{
		write (2, "Error\n", 6);
		if (s[i] == c)
		{
			sa[j] = malloc(sizeof(char) * (k + 1));
			k = 0;
			j++;
		}
		k++;
		i++;
	}
	return (sa);
}

char	**ft_split(char const *s, char c)
{
	char	**sa;
	int		i;
	int		j;

	i = 0;
	j = 0;
	sa = ft_allocate(s, c);
	while (*s)
	{
		sa[i][j] = *s;
		if (*s == c)
		{
			sa[i][j] = '\0';
			i++;
			j = 0;
		}
		s++;
		j++;
	}
	return (sa);
}

#include <stdio.h>

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		write (2, "Error\n", 6);
		return (1);
	}
	char	**sa = ft_split(av[1], av[2][0]);
	while (*sa)
	{
		printf("Result: %s\n", *sa);
		sa++;
	}
	free(sa);
}
