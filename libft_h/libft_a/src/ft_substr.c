/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neoyuls <neoyuls@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 05:09:38 by neoyuls           #+#    #+#             */
/*   Updated: 2026/09/15 12:31:10 by neoyuls          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*allocate(unsigned int n, unsigned int start, size_t len)
{
	char	*substr;

	if (len <= n - start)
	{
		substr = malloc(sizeof(char) * (len + 1));
	}
	if (len > n - start)
	{
		substr = malloc(sizeof(char) * (n - start + 1));
	}
	return (substr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i;

	i = ft_strlen(s);
	if (i < start)
		return (NULL);
	substr = allocate(i, start, len);
	i = 0;
	while (i < len && s[start + i])
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
