/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putsigned.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvernon <jvernon@student.42malaga.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 23:36:06 by jvernon           #+#    #+#             */
/*   Updated: 2026/10/02 15:12:47 by jvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putsigned(long nbr, char *base)
{
	int	baselen;
	int	printed;

	baselen = ft_strlen(base);
	printed = 0;
	if (nbr < 0)
	{
		printed += putchar_return('-');
		nbr = -nbr;
	}
	if (nbr >= baselen)
	{
		printed += putunsigned((nbr / baselen), base);
		printed += putchar_return(base[nbr % baselen]);
	}
	else
		printed += putchar_return(base[nbr % baselen]);
	return (printed);
}

/*
#include <stdio.h>
#include <stdlib.h>
int main(int ac, char **av)
{
	if (ac != 2)
		return 1;
	char base[17] = "0123456789abcdef";
	char base2[11] = "0123456789";
	int number = atoi(av[1]);

	write(1, "number: ", 8);
	printf("\nlen:%u\n", putnumber(number, base));
	printf("expected output: %x \n", number);
	write(1, "number: ", 8);
	printf("\nlen:%u\n", putnumber(number, base2));
	return 0;
}
*/
