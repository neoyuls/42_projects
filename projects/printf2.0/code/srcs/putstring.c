/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstring.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvernon <jvernon@student.42malaga.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 15:17:43 by jvernon           #+#    #+#             */
/*   Updated: 2026/10/02 01:41:51 by jvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putstring(char *s)
{
	int	i;

	if (!s)
		return ((int)write(1, "(null)", 6));
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}
