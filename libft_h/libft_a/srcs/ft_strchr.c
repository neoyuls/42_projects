/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neoyuls <neoyuls@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 12:33:38 by neoyuls           #+#    #+#             */
/*   Updated: 2026/09/14 05:06:06 by neoyuls          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	tofind;

	i = 0;
	tofind = (char)c;
	while (s[i] != '\0')
	{
		if (s[i] == tofind)
			return ((char *)(s + i));
		i++;
	}
	if (tofind == 0)
	{
		return ((char *)(s + i));
	}
	return (NULL);
}
