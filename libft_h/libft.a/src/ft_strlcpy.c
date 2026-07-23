/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neoyuls <neoyuls@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 18:10:17 by neoyuls           #+#    #+#             */
/*   Updated: 2026/07/23 10:26:36 by neoyuls          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// UNFINISHED(?) I DONT LIKE THIS FUNCTION
unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (src[i])
		i++;
	if (size == 0)
		return (i);
	while (j < size - 1 && src[j])
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = '\0';
	return (i);
}
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	if (ac != 3)
		return (1);
	if (atoi(av[2]) < 0)
	{
		write (2, "Error!\n", 7);
		return (1);
	}
	unsigned int size = (unsigned int)atoi(av[2]);
	char dest[50];
	char dest2[50];
	char *src = av[1];
	printf("my function: \n");
	unsigned int r1 = ft_strlcpy(dest, src, size);
	printf("\tsource: %s\n", src);
	printf("\tdest: %s\n", dest);
	printf("\treturn: %d\n", r1);
	unsigned int r2 = strlcpy(dest2, src, size);
	printf("string.h function: \n");
	printf("\tsource: %s\n", src);
	printf("\tdest: %s\n", dest);
	printf("\treturn: %d\n", r2);
	return (0);
}
*/
