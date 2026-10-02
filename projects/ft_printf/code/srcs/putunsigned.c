/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putunsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvernon <jvernon@student.42malaga.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 14:58:09 by jvernon           #+#    #+#             */
/*   Updated: 2026/10/02 15:10:56 by jvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putunsigned(unsigned long nbr, char *base)
{
	unsigned long	baselen;
	int				printed;

	baselen = ft_strlen(base);
	printed = 0;
	if (nbr >= baselen)
	{
		printed += putunsigned((nbr / baselen), base);
		printed += putchar_return(base[nbr % baselen]);
	}
	else
		printed += putchar_return(base[nbr % baselen]);
	return (printed);
}
