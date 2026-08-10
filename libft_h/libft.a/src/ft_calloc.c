/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neoyuls <neoyuls@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 04:17:55 by neoyuls           #+#    #+#             */
/*   Updated: 2026/08/10 13:24:36 by neoyuls          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(unsigned int n, unsigned int size)
{
	unsigned char	*ptr;

	ptr = malloc(size * n);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, n);
	if (n == 0)
		*ptr = 0;
	return (ptr);
}
