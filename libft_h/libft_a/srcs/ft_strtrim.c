/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvernon <jvernon@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 04:55:07 by jvernon           #+#    #+#             */
/*   Updated: 2026/09/19 09:40:02 by jvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_chars(char const c, char const *set)
{
	unsigned int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static char	*fill(char const *s1, char const *set)
{
	unsigned int	i;
	unsigned int	j;
	char			*trimmed;

	i = 0;
	j = ft_strlen(s1);
	if (j > 0)
		j--;
	while (check_chars(s1[i], set) == 1)
		i++;
	while (check_chars(s1[j], set) == 1 && j != 0)
		j--;
	trimmed = ft_substr(s1, i, j - i + 1);
	return (trimmed);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*trimmed;

	trimmed = fill(s1, set);
	if (!trimmed)
		return (NULL);
	return (trimmed);
}
