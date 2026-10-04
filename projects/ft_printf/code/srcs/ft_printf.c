/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvernon <jvernon@student.42malaga.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 07:21:20 by jvernon           #+#    #+#             */
/*   Updated: 2026/10/04 18:27:49 by jvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_arg(char c, va_list ap)
{
	if (c == 'c')
		return (putchar_return((char)va_arg(ap, int)));
	if (c == 's')
		return (putstring(va_arg(ap, char *)));
	if (c == 'p')
		return (putpointer(va_arg(ap, void *)));
	if (c == 'd' || c == 'i')
		return (putsigned(va_arg(ap, int), "0123456789"));
	if (c == 'u')
		return (putunsigned(va_arg(ap, unsigned int), "0123456789"));
	if (c == 'x')
		return (putunsigned(va_arg(ap, unsigned int), "0123456789abcdef"));
	if (c == 'X')
		return (putunsigned(va_arg(ap, unsigned int), "0123456789ABCDEF"));
	if (c == '%')
		return ((int)write(1, &c, 1));
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	i;
	int		len;

	if (!format)
		return (-1);
	i = 0;
	len = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] != '%')
			len += (int)write(1, &format[i], 1);
		else
		{
			i++;
			len += check_arg(format[i], ap);
		}
		if (format[i])
			i++;
	}
	va_end(ap);
	return (len);
}
