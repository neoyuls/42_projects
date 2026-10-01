/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvernon <jvernon@student.42malaga.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 08:03:51 by jvernon           #+#    #+#             */
/*   Updated: 2026/09/30 17:37:16 by jvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		putstring(char *s);
int		putptr(void *p);
int		putcharacter(int);
int		putnumber(int nb);
int		putunsigned(unsigned int nbr);
int		puthexlower(int nbr);
int		puthexupper(int nbr);

#endif
