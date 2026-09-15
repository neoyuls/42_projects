/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neoyuls <neoyuls@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 05:09:38 by neoyuls           #+#    #+#             */
/*   Updated: 2026/09/15 04:07:35 by neoyuls          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*allocate(unsigned int n, unsigned int start, size_t len)
{
	char	*substr;

	if (n - start > len)
		substr = malloc(sizeof(char) * (len + 1));
	if (start + len > n)
		substr = malloc(sizeof(char) * (n - start + 1));
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
