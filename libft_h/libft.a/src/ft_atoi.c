/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neoyuls <neoyuls@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 18:27:01 by neoyuls           #+#    #+#             */
/*   Updated: 2026/07/20 18:56:38 by neoyuls          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
// UNFINISHED!
int	ft_atoi(const char *nbr)
{
	unsigned int	i;
	int	num;
	int sign;

	i = 0;
	num = 0;
	sign = 1;
	
	if (nbr[0] == '-')
	{
		sign = -1;
		i++;
	}
	while (nbr[i])
	{
		num = (num * 10) + (nbr[i] - 48);
		i++;
	}
	return (num * sign);
}

#include <stdio.h>

int	main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	int result = ft_atoi(av[1]);
	printf("Atoi output = %d \n", result);
	return 0;
}
