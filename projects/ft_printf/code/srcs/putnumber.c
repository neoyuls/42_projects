/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnumber.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvernon <jvernon@student.42malaga.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 number:38:42 by jvernon           #+#    #+#             */
/*   Updated: 2026/10/01 15:46:37 by jvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

unsigned int	putnumber(int nbr, char *base, unsigned int len)
{
	long	nb;
	int		baselen;

	baselen = ft_strlen(base);
	if (nbr == 0)
		return ((unsigned int)write(1, "0", 1));
	nb = nbr;
	if (nbr < 0 && baselen == 10) // how do I handle other bases?
	{
		nb = -nb;
		len += (unsigned int)write(1, "-", 1);
	}
	if (nb >= baselen)
	{
		putnumber((int)(nb / baselen), base, len);
		len += (unsigned int)write(1, &base[nb % baselen], 1);
	}
	else
		len += (unsigned int)write(1, &base[nb], 1);
	len++;
	return (len);
}

//TESTING HARNESS, DELETE OR COMMENT OUT LATER
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
	printf("\nlen:%u\n", putnumber(number, base, 0));
	printf("expected output: %x \n", number);
	write(1, "number: ", 8);
	printf("\nlen:%u\n", putnumber(number, base2, 0));
	return 0;
}
