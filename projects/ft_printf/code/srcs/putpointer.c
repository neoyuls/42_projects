/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putpointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvernon <jvernon@student.42malaga.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 15:18:28 by jvernon           #+#    #+#             */
/*   Updated: 2026/10/02 02:08:21 by jvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putpointer(void *pointer)
{
	long long	ptrvalue;
	int			returnlen;

	if (!pointer)
		return ((int)write(1, "(nil)", 5));
	ptrvalue = (long long)pointer;
	returnlen = (int)write(1, "0x", 2);
	returnlen += putnumber(ptrvalue, "0123456789abcdef");
	return (returnlen);
}
