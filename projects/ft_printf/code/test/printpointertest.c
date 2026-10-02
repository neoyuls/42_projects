#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int	main(void)
{
	printf("stdio: ");
	printf("%p %p \n", (void *)LONG_MIN, (void *)LONG_MAX);
	ft_printf("mine: ");
	ft_printf("%p %p \n", LONG_MIN, LONG_MAX);
	return (0);
}
