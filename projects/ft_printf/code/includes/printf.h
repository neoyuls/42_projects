/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvernon <jvernon@student.42malaga.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 08:03:51 by jvernon           #+#    #+#             */
/*   Updated: 2026/09/27 08:46:37 by jvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "libft.h"
# include <stdarg.h>

typedef struct s_vars
{
}				t_vars;

typedef struct s_counters
{
	int			i;
	int			j;
	int			k;
	int			l;
}				t_counters;

void	print_number(int nb);
void	print_unsigned(unsigned int nb);
void	print_numbase(int nb);

int		ft_printf(const char *format, ...);

#endif
