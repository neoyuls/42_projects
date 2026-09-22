/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvernon <jvernon@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 00:37:06 by jvernon           #+#    #+#             */
/*   Updated: 2026/09/22 05:03:50 by jvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_lstsize(t_list *lst)
{
	unsigned int	size;

	if (!lst)
		return (NULL);
	size = 0;
	while(lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}
