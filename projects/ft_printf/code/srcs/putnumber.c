/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnumber.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvernon <jvernon@student.42malaga.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 number:38:42 by jvernon           #+#    #+#             */
/*   Updated: 2026/10/01 16:51:36 by jvernon          ###   ########.fr       */
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

unsigned int	putchar_return(char c)
{
	return ((unsigned int)write (1, &c, 1));
}

unsigned int	putnumber(long nbr, char *base, unsigned int len)
{
	unsigned int	baselen;

	baselen = ft_strlen(base);
	if (nbr < 0)
	{
		if (baselen == 10)
		{
			len += putchar_return('-');
			nbr = -nbr;
		}
		else
			nbr = (unsigned int)nbr;
	}
	if (nbr >= baselen)
	{
		putnumber((nbr / baselen), base, len++);
		len += putchar_return(base[nbr %  baselen]);
	}
	else
		len += putchar_return(base[nbr %  baselen]);
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
