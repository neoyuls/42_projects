/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neoyuls <neoyuls@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 11:18:53 by neoyuls           #+#    #+#             */
/*   Updated: 2026/07/23 12:14:21 by neoyuls          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memmove(void *dest, const void *src, unsigned int n)
{
	unsigned int	i;
	unsigned char	tmp[n];
	unsigned char	*source;
	unsigned char	*destination;

	destination = (unsigned char *)dest;
	source = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		tmp[i] = source[i];
		destination[i] = tmp[i];
		i++;
	}
	return (dest);
}
/*
#include <stdio.h>
#include <stdlib.h>
int	main(int ac, char **av)
{
	if (ac != 3)
		return 1;
	char dest[20];
	ft_memmove(dest, av[1], (unsigned int)atoi(av[2]));
	printf("%s\n", dest);
	return 0;
}
*/
