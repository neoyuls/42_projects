/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvernon <jvernon@student.42malaga.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 08:03:51 by jvernon           #+#    #+#             */
/*   Updated: 2026/10/02 15:14:21 by jvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int				ft_printf(const char *format, ...);
int				ft_strlen(char *s);
int				putstring(char *s);
int				putpointer(void *p);
int				puthexlower(int nbr);
int				puthexupper(int nbr);
int				putchar_return(char c);
int				putsigned(long nbr, char *base);
int				putunsigned(unsigned long nbr, char *base);

#endif
