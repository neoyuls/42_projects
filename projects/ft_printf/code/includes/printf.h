/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvernon <jvernon@student.42malaga.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 08:03:51 by jvernon           #+#    #+#             */
/*   Updated: 2026/09/30 15:16:51 by jvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>

void	print_number(int nb);
void	print_unsigned(unsigned int nb);
void	print_numbase(int nb, char *base);

int		ft_printf(const char *format, ...);

#endif
