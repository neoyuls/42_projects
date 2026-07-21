/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neoyuls <neoyuls@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 14:13:41 by neoyuls           #+#    #+#             */
/*   Updated: 2026/07/21 14:16:08 by neoyuls          ###   ########.fr       */
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
	if (nbr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (nbr[i] == '+')
		i++;
	while (nbr[i] >= 48 && nbr[i] <= 57)
	{
		num = (num * 10) + (nbr[i] - 48);
		i++;
	}
	return (num * sign);
}
/* TESTING
#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	int result = ft_atoi(av[1]);
	int r2 = atoi(av[1]);
	printf("ft_atoi output = %d \n", result);
	printf("stdlib atoi = %d \n", r2);
	return 0;
}
*/
