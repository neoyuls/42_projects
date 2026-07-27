/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neoyuls <neoyuls@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 04:17:55 by neoyuls           #+#    #+#             */
/*   Updated: 2026/07/27 12:35:28 by neoyuls          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(unsigned int n, unsigned int size)
{
	unsigned char	*ptr;
	unsigned int	i;

	i = 0;
	ptr = malloc(size);
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
	if (n == 0)
		*ptr = 0;
	return (ptr);
}
