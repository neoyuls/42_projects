/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neoyuls <neoyuls@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 06:00:42 by neoyuls           #+#    #+#             */
/*   Updated: 2026/09/16 16:08:39 by neoyuls          ###   ########.fr       */
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

static char	**substrings(char **arr, char const *s, char c)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		if (s[i] != c)
		{
			j = 0;
			while (s[i + j] != c || s[i + j] == '\0')
				j++;
			arr[k] = ft_substr(s, i, j - 1);
			k++;
			i += j - 1;
		}
	}
	arr[k] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	count;
	char			**arr;

	count = count_words(s, c);
	arr = malloc(sizeof(char *) * (count + 1));
	if (!arr)
		return (NULL);
	arr = substrings(arr, s, c);
	return (arr);
}
