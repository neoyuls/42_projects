/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neoyuls <neoyuls@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 14:36:33 by neoyuls           #+#    #+#             */
/*   Updated: 2026/07/21 17:18:48 by neoyuls          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
➜  libft.a git:(main) ./a.out "-23534500000004210000....412321312"
	ft_atoi output	= -313425232
	stdlib atoi 	= 0
➜  libft.a git:(main) ✗ ./a.out "999999999999990909090....412321312"
	ft_atoi output  = -569030494
	stdlib atoi     = -1
	
	why does this happen?
 */
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
