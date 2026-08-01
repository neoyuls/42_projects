/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neoyuls <neoyuls@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 17:42:34 by neoyuls           #+#    #+#             */
/*   Updated: 2026/08/01 12:57:31 by neoyuls          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// UNCLEAR IF DONE, REVISIT LATER, ALSO WRITE A MAIN LAZY ASS
void	ft_bzero(void *s, unsigned int n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	if (n == 0)
		return ;
	ptr = ft_memset(s, 0, n);
}
