/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flags_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvernon <jvernon@student.42malaga.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 01:54:27 by jvernon           #+#    #+#             */
/*   Updated: 2026/10/05 02:25:50 by jvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
//#include "ft_printf.h"

//int	main(int argcount, char *argarray[])
int	main(void)
{
	/*
	if (argcount != 2)
	{
		write(2, "Enter 1 string\n", 15);
		return (1);
	}
	*/
	// '-'
	printf("string: \"%f\" \noutput with '-' flag: \n\"%-20.2f\"\n", 231.421321, 231.421321);
	//ft_printf("string: \"%s\" \noutput with '-' flag: \n\"%-s\"\n", av[1], av[1])
	return (0);
}
