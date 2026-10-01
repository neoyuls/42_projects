/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnumber.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvernon <jvernon@student.42malaga.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 17:38:42 by jvernon           #+#    #+#             */
/*   Updated: 2026/10/01 13:50:00 by jvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	putnumber(int nbr, char *base, unsigned int len)
{
	long	nb;
	int		baselen;

	if (nbr == 0)
		return ((unsigned int)write(1, "0", 1));
	nb = nbr;
	if (nbr < 0 && ft_strlen(base) == 10)
	{
		nb = -nbr;
		len += (unsigned int)write(1, "-", 1);
	}
	if (nb >= ft_strlen(base))
	{

}
	/*
{
	long	nb;

	nb = nbr;
	if (nbr < 0)
	{
		write (1, "-", 1);
		nb = -nb;
		len++;
	}
	if (tmp >= 10)
	{
		putnumber((int)(nb / 10), base, len + 1);
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
*/
