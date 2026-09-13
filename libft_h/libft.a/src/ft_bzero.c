/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neoyuls <neoyuls@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 17:42:34 by neoyuls           #+#    #+#             */
/*   Updated: 2026/09/13 14:20:08 by neoyuls          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// UNCLEAR IF DONE, REVISIT LATER
void	ft_bzero(void *s, unsigned int n)
{
	if (n == 0)
		return ;
	ft_memset(s, 0, n);
}
