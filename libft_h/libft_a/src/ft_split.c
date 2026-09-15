/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neoyuls <neoyuls@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 06:00:42 by neoyuls           #+#    #+#             */
/*   Updated: 2026/09/15 08:49:38 by neoyuls          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	**allocate(char **strarr, char const *s, char c)
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
			strarr[k] = malloc(sizeof(char) * (j + 1));
			k++;
			j = 0;
		}
		i++;
		j++;
	}
	strarr[k] = malloc(sizeof(char) * (j + 1));
	return (strarr);
}

char	**fill(char **strarr, char const *s, char c)
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
			strarr[j][k] = '\0';
			j++;
			k = 0;
		}
		strarr[j][k] = s[i];
		i++;
		k++;
	}
	strarr[j][k] = '\0';
	return (strarr);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	i;
	unsigned int	count;
	char			**strarr;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			count++;
		i++;
	}
	strarr = malloc (sizeof(char *) * (count + 1));
	if (!strarr)
		return (NULL);
	strarr = allocate(strarr, s, c);
	strarr = fill(strarr, s, c);
	return (strarr);
}
