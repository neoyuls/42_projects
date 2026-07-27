/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neoyuls <neoyuls@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 04:03:36 by neoyuls           #+#    #+#             */
/*   Updated: 2026/07/27 04:15:33 by neoyuls          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char				*ft_strchr(const char *s, int c);
char				*ft_strnstr(const char *big,
						const char *little, unsigned int n);
char				*ft_strrchr(const char *s, int c);
int					ft_atoi(const char *nbr);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_memcmp(const void *s1, const void *s2, unsigned int n);
int					ft_strncmp(const char *s1, const char *s2, unsigned int n);
int					ft_tolower(int c);
int					ft_toupper(int c);
unsigned int		ft_strlcat(char *dest, char *src, unsigned int size);
unsigned int		ft_strlcpy(char *dest, const char *src, unsigned int size);
unsigned int		ft_strlen(char *s);
void				ft_bzero(void *s, unsigned int n);
void				*ft_memchr(const void *s, int c, unsigned int n);
void				*ft_memcpy(void *dest, const void *src, unsigned int n);
void				*ft_memmove(void *dest, const void *src, unsigned int n);
void				*ft_memset(void *s, int c, unsigned int n);
void				*ft_calloc(unsigned int n, unsigned int size);
