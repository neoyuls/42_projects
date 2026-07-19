/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neoyuls <neoyuls@student.42.es>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 19:01:11 by neoyuls           #+#    #+#             */
/*   Updated: 2026/07/19 19:12:08 by neoyuls          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_bzero(void *s, unsigned int n)
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
		*(unsigned char *)s = ptr[i];
		*(unsigned char *)s = *(unsigned char *)(s + 1);
		i++;
	}
}
