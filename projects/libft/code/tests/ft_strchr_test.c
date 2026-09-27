/* ************************************************************************** */
/*                                                                            */
/*   ft_strchr_test.c                                                         */
/*                                                                            */
/*                                                                            */
/*   Harness for ft_strchr: compares it with libc strchr.                     */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"
# include <string.h>
# include <stdio.h>

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		write(2, "Error!\n", 7);
		return (1);
	}
	write(1, "My function: ", 12);
	printf("%s\n", ft_strchr(av[1], (int)av[2][0]));
	write(1, "String.h function: ", 18);
	printf("%s\n", strchr(av[1], (int)av[2][0]));
	return (0);
}
