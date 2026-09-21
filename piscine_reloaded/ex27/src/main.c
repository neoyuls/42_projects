/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvernon <jvernon@student.42malaga.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 14:34:14 by jvernon           #+#    #+#             */
/*   Updated: 2026/09/14 15:45:23 by jvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	open_read(char *path);

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		write (2, "File name missing.\n", 19);
		return (1);
	}
	if (ac > 2)
	{
		write (2, "Too many arguments.\n", 20);
		return (1);
	}
	if (open_read(av[1]) == 0)
	{
		write (2, "Cannot read file.\n", 18);
		return (1);
	}
	else
		return (0);
}
