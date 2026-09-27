/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvernon <jvernon@student.42malaga.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 07:21:20 by jvernon           #+#    #+#             */
/*   Updated: 2026/09/27 09:14:47 by jvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printf(const char *format, ...)
{
	size_t	len;
	size_t	count;

	len = -1;
	count = 0;
	while (++len)
		if (format[len] == '%')
			count++;

}
