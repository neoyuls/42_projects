/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvernon <jvernon@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 05:09:38 by jvernon           #+#    #+#             */
/*   Updated: 2026/09/20 21:24:42 by jvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*allocate(unsigned int n, unsigned int start, size_t len)
{
	char	*substr;

	if (len <= n - start)
		substr = malloc(sizeof(char) * (len + 1));
	if (len > n - start)
		substr = malloc(sizeof(char) * (n - start + 1));
	return (substr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i;

	i = ft_strlen(s);
	if (i < start)
		return (ft_strdup(""));
	substr = allocate(i, start, len);
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
