/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neoyuls <neoyuls@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 17:42:34 by neoyuls           #+#    #+#             */
/*   Updated: 2026/08/10 13:23:12 by neoyuls          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// UNCLEAR IF DONE, REVISIT LATER, ALSO WRITE A MAIN LAZY ASS
void	ft_bzero(void *s, unsigned int n)
{
	if (n == 0)
		return ;
	ft_memset(s, 0, n);
}
