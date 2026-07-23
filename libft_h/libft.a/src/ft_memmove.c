/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neoyuls <neoyuls@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 11:18:53 by neoyuls           #+#    #+#             */
/*   Updated: 2026/07/23 12:19:39 by neoyuls          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memmove(void *dest, const void *src, unsigned int n)
{
	unsigned int	i;
	unsigned char	*tmp;
	unsigned char	*destination;

	destination = (unsigned char *)dest;
	tmp = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
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
