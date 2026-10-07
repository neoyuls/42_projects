/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvergon <jvernon@student.42malaga.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 15:49:48 by jvernon           #+#    #+#             */
/*   Updated: 2026/10/06 13:38:21 by jvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 42

typedef struct s_lines
{
    static char *rest;
    char *line;
    int  Index;
} t_lines;

char	*get_next_line(int fd);
char	*read_line(int fd, char *rest);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
char    *ft_strjoin(char const *s1, char const *s2);
char    *ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);

#endif
