/* ************************************************************************** */
/*                                                                            */
/*   ft_itoa_test.c                                                           */
/*                                                                            */
/*                                                                            */
/*   Harness for ft_itoa: prints INT_MIN, INT_MAX, 0 and small values.        */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	main(void)
{
	char *nbr;

	nbr = ft_itoa(INT_MIN);
	write(1, nbr, ft_strlen(nbr));
	write(1, "\n", 1);
	free(nbr);

	nbr = ft_itoa(5);
	write(1, nbr, ft_strlen(nbr));
	write(1, "\n", 1);
	free(nbr);

	nbr = ft_itoa(0);
	write(1, nbr, ft_strlen(nbr));
	write(1, "\n", 1);
	free(nbr);

	nbr = ft_itoa(-5);
	write(1, nbr, ft_strlen(nbr));
	write(1, "\n", 1);
	free(nbr);

	nbr = ft_itoa(-200);
	write(1, nbr, ft_strlen(nbr));
	write(1, "\n", 1);
	free(nbr);

	nbr = ft_itoa(INT_MAX);
	write(1, nbr, ft_strlen(nbr));
	write(1, "\n", 1);
	free(nbr);

	return (0);
}
