/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putpointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvernon <jvernon@student.42malaga.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 15:18:28 by jvernon           #+#    #+#             */
/*   Updated: 2026/10/02 15:20:14 by jvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putpointer(void *pointer)
{
	unsigned long	ptrvalue;
	int				returnlen;

	if (!pointer)
		return ((int)write(1, "(nil)", 5));
	ptrvalue = (unsigned long)pointer;
	returnlen = (int)write(1, "0x", 2);
	returnlen += putunsigned(ptrvalue, "0123456789abcdef");
	return (returnlen);
}
