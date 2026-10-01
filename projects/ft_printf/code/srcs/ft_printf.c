/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvernon <jvernon@student.42malaga.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 07:21:20 by jvernon           #+#    #+#             */
/*   Updated: 2026/10/01 13:49:52 by jvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	check_arg(char c, va_list ap)
{
	if (c == 'c')
		return ((int)write(1, &c, 1));
	if (c == 's')
		return (putstring(va_arg(ap, char *)));
	if (c == 'p')
		return (putptr(va_arg(ap, void *)));
	if (c == 'd' || c == 'i')
		return (putnumber(va_arg(ap, int), "0123456789", 0));
	if (c == 'u')
		return (putnumber(va_arg(ap, unsigned int), "0123456789", 0));
	if (c == 'x')
		return (putnumber(va_arg(ap, int), "0123456789abcdef", 0));
	if (c == 'X')
		return (putnumber(va_arg(ap, int), "0123456789ABCDEF", 0));
	if (c == '%')
		return ((int)write(1, &c, 1));
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	i;
	int		len;

	va_start(ap, format);
	i = -1;
	len = 0;
	while (format[i++])
	{
		if (format[i] == '%')
			len += check_arg(format[i++], ap);
		else
			len += ((char)write(1, &format[i], 1));
	}
	va_end(ap);
	return (len);
}
