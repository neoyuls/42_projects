/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvernon <jvernon@student.42malaga.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 18:43:47 by jvernon           #+#    #+#             */
/*   Updated: 2026/10/04 20:27:22 by jvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *get_next_line(int fd)
{
	ssize_t		bytesread;
	size_t		number_bytes;
	static char	*buffer;

	buffer = malloc(sizeof(/*figure this out*/) + 1);
	while (bytesread != -1)
		bytesread = read(fd, buffer, number_bytes);

}
