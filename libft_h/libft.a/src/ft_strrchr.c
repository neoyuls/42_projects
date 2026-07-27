/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neoyuls <neoyuls@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 22:36:31 by neoyuls           #+#    #+#             */
/*   Updated: 2026/07/26 23:00:49 by neoyuls          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*found;
	char	tofind;
	int		i;
	
	i = 0;
	found = ((void *)0);
	tofind = (char)c;
	while (*s != '\0')
	{
		if (*s == tofind)
		{
			i += 1;
			found = (char *)s;
		}
		s++;
	}
	return ((void *)0);
}
// UNFINISHED, FINISH AFTER WORKING ON STRCHR
