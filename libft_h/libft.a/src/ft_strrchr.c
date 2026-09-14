/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neoyuls <neoyuls@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 22:36:31 by neoyuls           #+#    #+#             */
/*   Updated: 2026/09/14 05:04:56 by neoyuls          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*found;

	found = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
			found = (char *)s;
		s++;
	}
	if ((char)c == 0)
		found = (char *)s;
	return (found);
}
/*
char	*ft_strrchr(const char *s, int c)
{
	char	*found;

	found = ((void *)0);
	while (*s != '\0')
	{
		if (*s == (char)c)
		{
			found = (char *)s;
		}
		s++;
	}
	if (found != ((void *)0))
		return (found);
	if (*s == 0)
		return ((char *)s);
	return ((void *)0);
}
*/
