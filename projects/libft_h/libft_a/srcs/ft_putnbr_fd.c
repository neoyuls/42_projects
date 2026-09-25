/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvernon <jvernon@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 15:13:56 by jvernon           #+#    #+#             */
/*   Updated: 2026/09/19 16:00:14 by jvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	tmp;

	tmp = n;
	if (tmp < 0)
	{
		write(fd, "-", 1);
		tmp = -tmp;
	}
	if (tmp >= 10)
	{
		ft_putnbr_fd(tmp / 10, fd);
		tmp = tmp % 10 + '0';
		write(fd, &tmp, 1);
	}
	else
	{
		tmp += '0';
		write(fd, &tmp, 1);
	}
}
