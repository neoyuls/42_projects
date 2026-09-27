/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   testing all the "is x" functions in one go                               */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		write(2, "Introduce just one argument\n", 36);
		return (1);
	}
	for (int i = 0; i < ft_strlen(av[1]); i++)
	{
		char c = atoi(ft_isalpha((char)av[1][i]);
		write(1, &c, 1);
	}
}
