/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvernon <jvernon@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 06:00:42 by jvernon           #+#    #+#             */
/*   Updated: 2026/09/27 10:28:59 by jvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	count_words(char const *s, char c)
{
	unsigned int	count;
	unsigned int	i;

	i = 0;
	count = 0;
	if (s[i] != c && s[i] != '\0')
	{
		count++;
		i++;
	}
	while (s[i])
	{
		if (s[i] != c && s[i - 1] == c)
			count++;
		i++;
	}
	return (count);
}

static char	**if_fail(char **arr, unsigned int count)
{
	while (count > 0)
	{
		count--;
		free(arr[count]);
	}
	free(arr);
	return (NULL);
}

static char	**substrings(char **arr, char const *s, char c)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			j = 0;
			while (s[i + j] != c && s[i + j] != '\0')
				j++;
			arr[k] = ft_substr(s, i, j);
			if (!arr[k])
				return (if_fail(arr, k));
			k++;
			i += j;
		}
	}
	arr[k] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	count;
	char			**arr;

	if (!s)
		return (NULL);
	count = count_words(s, c);
	arr = malloc(sizeof(char *) * (count + 1));
	if (!arr)
		return (NULL);
	arr = substrings(arr, s, c);
	return (arr);
}
