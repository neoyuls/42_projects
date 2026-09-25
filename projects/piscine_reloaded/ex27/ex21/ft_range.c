/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvernon <jvernon@student.42malaga.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 16:58:56 by jvernon           #+#    #+#             */
/*   Updated: 2026/09/09 17:26:55 by jvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*allocate(int min, int max)
{
	int	i;
	int	j;
	int	*range;

	i = min;
	j = 1;
	while (i < max)
	{
		j++;
		i++;
	}
	range = malloc(sizeof(int) * j);
	return (range);
}

int	*ft_range(int min, int max)
{
	int	i;
	int	*range;

	i = 0;
	if (min >= max)
		return ((void *)0);
	range = allocate(min, max);
	while (min < max)
	{
		range[i] = min;
		i++;
		min++;
	}
	return (range);
}
/*
#include <stdio.h>

int	main(int ac, char **av)
{
	if (ac != 3)
		return 1;
	int *range = ft_range(atoi(av[1]), atoi(av[2]));
	int i = 0;
	while (i <= 5)
	{
		printf("%d\n", range[i]);
		i++;
	}
	free(range);
	return 0;
}
*/
