/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neoyuls <neoyuls@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 04:55:07 by neoyuls           #+#    #+#             */
/*   Updated: 2026/09/15 06:00:27 by neoyuls          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*allocate(char const *s1, char const *set)
{
	char			*s;
	unsigned int	size;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	size = ft_strlen(s1);
	while (s1[i])
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				size--;
			}
			j++;
		}
		i++;
	}
	s = malloc(sizeof(char) * (size + 1));
	return (s);
}

char	*fill(char const *s1, char const *set, char *trimmed)
{
	unsigned int	j;
	unsigned int	k;
	unsigned int	i;

	k = 0;
	while (*s1)
	{
		j = 0;
		while (set[j])
		{
			if (set[j] == *s1)
				break ;
			j++;
		}
		if (set[j] == '\0')
		{
			trimmed[k] = *s1;
			k++;
		}
		s1++;
	}
	trimmed[k] = '\0';
	return (trimmed);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*trimmed;

	trimmed = allocate(s1, set);
	if (!trimmed)
		return (NULL);
	trimmed = fill(s1, set, trimmed);
	return (trimmed);
}

/*
char	*ft_strtrim(char const *s1, char const *set)
{
	char			*trimmed;
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	k = 0;
	trimmed = allocate(s1, set);
	if (!trimmed)
		return (NULL);
	while (s1[i])
	{
		j = 0;
		while (set[j])
		{
			if (set[j] == s1[i])
				break ;
			j++;
		}
		if (set[j] == '\0')
		{
			trimmed[k] = s1[i];
			k++;
		}
		i++;
	}
	trimmed[k] = '\0';
	return (trimmed);
}
*/
