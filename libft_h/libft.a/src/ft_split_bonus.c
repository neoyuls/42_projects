/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neoyuls <neoyuls@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 20:31:57 by neoyuls           #+#    #+#             */
/*   Updated: 2026/08/06 14:15:01 by neoyuls          ###   ########.fr       */
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
