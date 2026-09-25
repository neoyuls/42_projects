/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvernon <jvernon@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 14:36:33 by jvernon           #+#    #+#             */
/*   Updated: 2026/08/03 12:44:25 by jvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
