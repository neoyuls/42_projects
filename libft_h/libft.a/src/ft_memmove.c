/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neoyuls <neoyuls@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 11:18:53 by neoyuls           #+#    #+#             */
/*   Updated: 2026/09/14 01:46:14 by neoyuls          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d2;
	unsigned char		*s2;

	s2 = (unsigned char *)src;
	d2 = (unsigned char *)dest;
	i = 0;
	if (dest > src)
	{
		while (n > 0)
		{
			*(d2 + n - 1) = *(s2 + n - 1);
			n--;
		}
	}
	else if (src > dest)
	{
		while (i < n)
		{
			*(d2++) = *(s2++);
			i++;
		}
	}
	return (d2);
}
