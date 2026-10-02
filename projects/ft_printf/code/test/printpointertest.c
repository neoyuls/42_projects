#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int	main(void)
{
	printf("stdio: ");
	printf("%p %p \n", (void *)LONG_MIN, (void *)LONG_MAX);
	ft_printf("mine: ");
	ft_printf("%p %p \n", LONG_MIN, LONG_MAX);

	ft_printf("ULONG: \n");
	ft_printf("stdio: ");
	printf(" %p %p \n", (void *)ULONG_MAX, (void *)-ULONG_MAX);
	ft_printf("mine: ");
	ft_printf(" %p %p \n", ULONG_MAX, -ULONG_MAX);
	return (0);
}
