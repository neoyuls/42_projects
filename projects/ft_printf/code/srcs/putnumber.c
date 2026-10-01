/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnumber.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvernon <jvernon@student.42malaga.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 17:38:42 by jvernon           #+#    #+#             */
/*   Updated: 2026/09/30 17:47:01 by jvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	putnumber(int nbr)
{
	long	nb;
	int		len;

	nb = nbr;
	len = 0;
	if (nbr < 0)
	{
		write (1, "-", 1);
		nb = -nb;
	}
	if (tmp >= 10)
	{
		putnumber((int)(nb / 10));
		nb = nb % 10 + '0';
		write(1, &nb, 1);
	}
	else
	{
		nb += '0';
		write(1, &nb, 1);
	}
	return (len);
}
