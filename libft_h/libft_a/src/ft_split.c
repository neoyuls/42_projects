/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neoyuls <neoyuls@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 06:00:42 by neoyuls           #+#    #+#             */
/*   Updated: 2026/09/15 11:24:50 by neoyuls          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	**allocate(char **arr, char const *s, char c)
{
	unsigned int i;
	unsigned int j;
	unsigned int k;

	i = 0;
	k = 0;
	if (s[i] == '\0')
	{
		return (NULL);
	}
	if (s[i] == c)
		i++;
	while (s[i])
	{
		j = 0;
		if (s[i - 1] == c && s[i] != c)
		{
			while (s[i + j] != c && s[i + j] != '\0')
				j++;
			arr[k] = malloc(sizeof(char) * (j + 1));
			i = i + j;
			k++;
		}
		i++;
	}
	return (arr);
}

char	**fill(char **arr, char const *s, char c)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c)
		{
			arr[j][k] = s[i];
			i++;
			k++;
		}
		if (s[i + 1] == c || s[i + 1] == '\0')
		{
			arr[j][k] = '\0';
			j++;
			k = 0;
		}
	}
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	i;
	unsigned int	count;
	char			**strarr;

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
	strarr = malloc (sizeof(char *) * (count + 1));
	if (!strarr)
		return (NULL);
	strarr = allocate(strarr, s, c);
	strarr = fill(strarr, s, c);
	return (strarr);
}
