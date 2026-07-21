/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neoyuls <neoyuls@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 14:36:33 by neoyuls           #+#    #+#             */
/*   Updated: 2026/07/21 17:20:51 by neoyuls          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nbr)
{
	int				num;
	int				sign;
	unsigned int	i;

	i = 0;
	num = 0;
	sign = 1;
	while ((nbr[i] == ' ')
		|| (nbr[i] >= '\t' && nbr[i] <= '\r'))
		i++;
	if (nbr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (nbr[i] == '+')
		i++;
	while (nbr[i] >= '0' && nbr[i] <= '9')
	{
		num = (num * 10) + (nbr[i] - '0');
		i++;
	}
	return (num * sign);
}
/*
#include <stdio.h>
#include <stdlib.h>

//int	main(int ac, char **av)
int	main(void)
{
//	if (ac != 2)
//	return (1);
//	int result = ft_atoi(av[1]);
//	int r2 = atoi(av[1]);
	int result = ft_atoi("\t\n\r-300");
	int r2 = atoi("\t\n\r-300");
	printf("\tft_atoi output \t= %d \n", result);
	printf("\tstdlib atoi \t= %d \n", r2);
	return 0;
}
*/
