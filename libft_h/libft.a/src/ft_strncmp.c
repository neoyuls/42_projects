/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neoyuls <neoyuls@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 00:49:43 by neoyuls           #+#    #+#             */
/*   Updated: 2026/07/27 01:31:43 by neoyuls          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (((s1[i] || s2[i]) != '\0') && i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
// Ill do memcmp first then this one
/*
#include <string.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		printf("Error\n");
		return 1;
	}
	printf("my function: %d\n", ft_strncmp(av[1], av[2], strlen(av[1])));
	printf("string.h function: %d\n", strncmp(av[1], av[2], strlen(av[1])));
	return 0;
}
*/
