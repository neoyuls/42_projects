/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvernon <jvernon@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 00:43:56 by jvernon           #+#    #+#             */
/*   Updated: 2026/09/22 05:15:09 by jvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	del(void *content)
{
	free(content);
}

void	ft_1stdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
}
