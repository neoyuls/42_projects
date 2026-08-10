/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neoyuls <neoyuls@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 11:18:53 by neoyuls           #+#    #+#             */
/*   Updated: 2026/07/23 12:25:17 by neoyuls          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// REVISIT LATER
void	*ft_memmove(void *dest, const void *src, unsigned int n)
{
	unsigned int	i;
	unsigned char	*tmp;
	unsigned char	*destination;

	destination = (unsigned char *)dest;
	tmp = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		destination[i] = tmp[i];
		i++;
	}
	return (dest);
}
