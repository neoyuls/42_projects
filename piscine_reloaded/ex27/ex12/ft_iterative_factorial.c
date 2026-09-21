/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvernon <jvernon@student.42malaga.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 16:56:42 by jvernon           #+#    #+#             */
/*   Updated: 2026/09/09 11:17:57 by jvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	f;

	f = 1;
	if (nb < 0)
		return (0);
	if (nb >= 13)
		return (0);
	while (nb > 0)
	{
		f = f * nb;
		nb--;
	}
	return (f);
}

/*
#include <stdio.h>

int	main (void)
{
	printf("%d", ft_iterative_factorial(0));
	return 0;
}
*/
