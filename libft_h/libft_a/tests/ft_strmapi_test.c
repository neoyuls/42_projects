/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvernon <jvernon@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 23:02:02 by jvernon           #+#    #+#             */
/*   Updated: 2026/09/17 23:14:55 by jvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	rot13_char(unsigned int i, char c)
{
	(void)i;
	if (c >= 'a' && c <= 'z')
		return ((char)((c - 'a' + 13) % 26 + 'a'));
	if (c >= 'A' && c <= 'Z')
		return ((char)((c - 'A' + 13) % 26 + 'A'));
	return (c);
}

int	main(int ac, char **av)
{
	char	*str;
	char	*str2;

	if (ac != 2)
	{
		write(2, "Insert 1 parameter.\n", 20);
		return (1);
	}
	str = ft_strmapi(av[1], rot13_char);
	if (!str)
	{
		write(2, "ft_strmapi returned NULL\n", 25);
		return (1);
	}
	write(1, "input			: ", 10);
	write(1, av[1], ft_strlen(av[1]));
	write(1, "\nrot13 : ", 9);
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	str2 = ft_strmapi(str, rot13_char);
	if (!str2)
	{
		write(2, "ft_strmapi returned NULL\n", 25);
		return (1);
	}
	write(1, "input(reverse)	: ", 17);
	write(1, str, ft_strlen(str));
	write(1, "\nrot13 : ", 9);
	write(1, str2, ft_strlen(str2));
	write(1, "\n", 1);
	free(str);
	free(str2);
	return (0);
}
