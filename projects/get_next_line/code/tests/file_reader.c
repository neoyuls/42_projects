/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvernon <jvernon@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 00:10:02 by jvernon           #+#    #+#             */
/*   Updated: 2026/10/11 03:43:00 by jvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
// Move this file up a dir before testing: `mv file_reader.c ..`
int	main()
{
	int fd1 = open("tests/bible_kjv.txt", O_RDONLY);
	int fd2 = open("tests/quran-simple.txt", O_RDONLY);
	char *line;
	char *line2;

	while ((line = get_next_line(fd1)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	while ((line2 = get_next_line(fd2)) != NULL)
	{
		printf("%s", line2);
		free(line2);
	}

}
