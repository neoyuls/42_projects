/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neoyuls <neoyuls@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 04:17:55 by neoyuls           #+#    #+#             */
/*   Updated: 2026/09/14 02:38:12 by neoyuls          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	unsigned char	*ptr;

	if (n == 0 || size == 0)
		return (malloc(0));
	if (n > ((size_t)-1) / size)
		return (NULL);
	ptr = malloc(size * n);
	if (!ptr)
		return (malloc(0));
	ft_bzero(ptr, size * n);
	return (ptr);
}
