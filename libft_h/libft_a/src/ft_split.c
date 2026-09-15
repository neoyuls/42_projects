/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neoyuls <neoyuls@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 06:00:42 by neoyuls           #+#    #+#             */
/*   Updated: 2026/09/15 12:32:18 by neoyuls          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*allocate(char **arr, char const *s, char c)
{
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
	allocate(strarr, s, c);
	return (strarr);
}
