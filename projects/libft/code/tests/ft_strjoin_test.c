/* ************************************************************************** */
/*                                                                            */
/*   ft_strjoin_test.c                                                        */
/*                                                                            */
/*                                                                            */
/*   Harness for ft_strjoin: prints both inputs and their concatenation.      */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		write (2, "Too few or too many arguments!\n", 30);
		return (1);
	}
	write(1, "s1:	", 4);
	write(1, av[1], ft_strlen(av[1]));
	write(1, "\n", 1);
	write(1, "s2:	", 4);
	write(1, av[2], ft_strlen(av[2]));
	write(1, "\n", 1);
	write(1, "strjoin result:	", 15);
	write(1, ft_strjoin(av[1], av[2]), ft_strlen(av[1]) + ft_strlen(av[2]));
	write(1, "\n", 1);
	return (0);
}
