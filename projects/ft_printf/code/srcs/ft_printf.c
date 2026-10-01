/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvernon <jvernon@student.42malaga.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 07:21:20 by jvernon           #+#    #+#             */
/*   Updated: 2026/09/30 17:48:24 by jvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	check_arg(char c, va_list ap)
{
	if (c == 'c')
	{
		va_arg(ap, int);
		return (1);
	}
	if (c == 's')
		return (putstring(va_arg(ap, char *)));
	if (c == 'p')
		return (putptr(va_arg(ap, void *)));
	if (c == 'd' || c == 'i')
	{
		putnumber(va_arg(ap, int))
		return (count_len(va_arg(ap, int)));
	}
	if (c == 'u')
		return (putunsigned(va_arg(ap, unsigned int)));
	if (c == 'x')
		return (puthexlower(va_arg(ap, char *)));
	if (c == 'X')
		return (puthexupper(va_arg(ap, char *)));
	if (c == '%')
		return ((int)write(1, "%", 1));
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
