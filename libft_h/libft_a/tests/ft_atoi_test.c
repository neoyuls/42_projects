# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		write (2, "Too few or too many arguments\n", 31);
		return 0;
	}
	int stdatoi = atoi(av[1]);
	int myatoi = ft_atoi(av[1]);
	
	printf("stdlib atoi: %d\n", stdatoi);
	printf("my atoi: %d\n", myatoi);
	return (0);
}
