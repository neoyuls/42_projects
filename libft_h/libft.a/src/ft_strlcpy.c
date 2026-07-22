/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neoyuls <neoyuls@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 18:10:17 by neoyuls           #+#    #+#             */
/*   Updated: 2026/07/21 18:01:43 by neoyuls          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// VERY UNFINISHED, WILL DO LATER
// I DONT LIKE THIS FUNCTION
unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if (size == 0)
		return (size);
	while (i < size - 1 && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	if (size >= i)
		dest[i] = '\0';
	return (i);
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	if (ac != 3)
		return (0);
	unsigned int size = (unsigned int)atoi(av[2]);
	char dest[50];
	char *src = av[1];
	printf("my function: \n");
	ft_strlcpy(dest, src, size);
	printf("\tsource: %s\n", src);
	printf("\tdest: %s\n", dest);
	strlcpy(dest, src, size);
	printf("string.h function: \n");
	printf("\tsource: %s\n", src);
	printf("\tdest: %s\n", dest);
	return (0);
}
