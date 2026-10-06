/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvergon <jvernon@student.42malaga.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 15:49:48 by jvernon           #+#    #+#             */
/*   Updated: 2026/10/05 19:19:35 by jvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>

# define BUFFER_SIZE 42

typedef struct	s_indices;
{
	int	i;
	int	j;
	int	k;
	int	l;
}		t_index;

char *get_next_line(int fd);

#endif
