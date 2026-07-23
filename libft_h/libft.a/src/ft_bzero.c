/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neoyuls <neoyuls@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 17:42:34 by neoyuls           #+#    #+#             */
/*   Updated: 2026/07/23 12:26:30 by neoyuls          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// UNCLEAR IF DONE, REVISIT LATER, ALSO WRITE A MAIN LAZY ASS
void	ft_bzero(void *s, unsigned int n)
{
	unsigned char	zero;
	unsigned char	*ptr;
	unsigned int	i;

	ptr = (unsigned char *)s;
	zero = 0;
	if (n == 0)
		return ;
	i = 0;
	while (i < n)
	{
		ptr[i] = zero;
		i++;
	}
}
