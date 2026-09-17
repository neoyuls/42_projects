/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neoyuls <jvernon@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 14:41:11 by neoyuls           #+#    #+#             */
/*   Updated: 2026/09/17 16:23:54 by neoyuls          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	count_len(int n)
{
	unsigned int	tmp;
	unsigned int	len;

	len = 1;
	tmp = n;
	if (n < 0)
	{
		len++;
		tmp = -tmp;
	}
	while (tmp > 0)
	{
		tmp = tmp / 10;
		len++;
	}
	return (len);
}

static void	fill_str(int n, unsigned int len, char *str)
{
	unsigned int	tmp;

	tmp = n;
	str[len] = '\0';
	len--;
	if (n < 0)
	{
		str[0] = '-';
		tmp = -tmp;
	}
	while (tmp > 0)
	{
		str[len] = (tmp % 10) + '0';
		len--;
		tmp /= 10;
	}
}

char	*ft_itoa(int n)
{
	unsigned int	len;
	char			*str;

	len = count_len(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	fill_str(n, len, str);
	return (str);
}
