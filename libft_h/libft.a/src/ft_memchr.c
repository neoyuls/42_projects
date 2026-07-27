/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neoyuls <neoyuls@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 01:32:18 by neoyuls           #+#    #+#             */
/*   Updated: 2026/07/27 01:55:57 by neoyuls          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memchr(const void *s, int c, unsigned int n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n > 0)
	{
		if (*str == (unsigned char)c)
			return (str);
		str++;
		n--;
	}
	return ((void *)0);
}

/*
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
int	main(int ac, char **av)
{
	if (ac != 4)
	{
		write(2, "Error\n", 6);
		return 1;
	}
	write(1, ft_memchr(av[1], atoi(av[2]), atoi(av[3])), 1);
	write(1, "\n", 1);
	write(1, memchr(av[1], atoi(av[2]), atoi(av[3])), 1);
	write(1, "\n", 1);
	return (0);
}
*/
