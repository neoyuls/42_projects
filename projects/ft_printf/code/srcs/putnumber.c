/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnumber.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvernon <jvernon@student.42malaga.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 23:36:06 by jvernon           #+#    #+#             */
/*   Updated: 2026/10/02 00:01:39 by jvernon          ###   ########.fr       */
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

unsigned int	count_len(long n)
{
	long	tmp;
	unsigned int	len;

	len = 0;
	tmp = n;
	if (n == 0)
		return (1);
	if (tmp < 0)
	{
		tmp = -tmp;
		len++;
	}
	while (tmp > 0)
	{
		tmp /= 10;
		len++;
	}
	return (len);
}

unsigned int	putnumber(long nbr, char *base)
{
	unsigned int	baselen;
	unsigned int	i;
	char 			arr[13];

	i = -1;
	baselen = ft_strlen(base);
	if (nbr < 0)
	{
		if (baselen == 10)
		{
			arr[i++] = '-';
//			len += putchar_return('-');
			nbr = -nbr;
		}
		else
			nbr = (unsigned int)nbr;
	}
	if (nbr >= baselen)
	{
		putnumber((nbr / baselen), base);
		putchar_return(base[nbr %  baselen]);
	}
	putchar_return(base[nbr %  baselen]);
	return (/*idk bro */);
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
	printf("\nlen:%u\n", putnumber(number, base));
	printf("expected output: %x \n", number);
	write(1, "number: ", 8);
	printf("\nlen:%u\n", putnumber(number, base2));
	return 0;
}
