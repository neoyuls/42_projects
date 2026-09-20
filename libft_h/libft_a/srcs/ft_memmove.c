/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvernon <jvernon@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 11:18:53 by jvernon           #+#    #+#             */
/*   Updated: 2026/09/20 16:27:54 by jvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	unsigned char		*s;

	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	if (d < s)
		while (n--)
			*d++ = *s++;
	else if (d > s)
		while (n--)
				d[n] = s[n];
	return (d);
}
