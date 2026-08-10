/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neoyuls <neoyuls@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 12:33:38 by neoyuls           #+#    #+#             */
/*   Updated: 2026/08/03 13:48:58 by neoyuls          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	tofind;

	tofind = (char)c;
	while (*s != '\0')
	{
		if (*s == tofind)
			return ((char *)s);
		s++;
	}
	if (*s == 0)
		return ((char *)s);
	else
		return ((void *)0);
}
