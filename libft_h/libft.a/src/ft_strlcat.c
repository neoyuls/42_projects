/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neoyuls <neoyuls@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 10:53:04 by neoyuls           #+#    #+#             */
/*   Updated: 2026/07/23 10:53:06 by neoyuls          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (src[i])
		i++;
	while (dest[j])
		j++;
	if (size == 0)
		return (i);	
	if (j > size)
		return (i + j);
	i = 0;
	while (j < size - 1 && src[i])
	{
		dest[j + i] = src[i];
		i++;
	}
	dest[j + i] = '\0';
	return (i + j);
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	if (ac != 4)
		return (1);
	if (atoi(av[3]) < 0)
	{
		write (2, "Error!\n", 7);
		return (1);
	}
	unsigned int size = (unsigned int)atoi(av[3]);
	char *dest = av[1];
	char *dest2 = av[1];
	char *src = av[2];
	char *src2 = av[2];
	printf("my function: \n");
	unsigned int r1 = ft_strlcat(dest, src, size);
	printf("\tsource: %s\n", src);
	printf("\tdest: %s\n", dest);
	printf("\treturn: %d\n", r1);
	unsigned int r2 = strlcat(dest2, src2, size);
	printf("string.h function: \n");
	printf("\tsource: %s\n", src2);
	printf("\tdest: %s\n", dest2);
	printf("\treturn: %d\n", r2);
	return (0);
}
