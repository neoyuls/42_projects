#include "libft.h"
#include "stdio.h"

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		write(2, "Error!\n", 7);
		return (1);
	}
	char *s = ft_substr(av[1], atoi(av[2]), atoi(av[3]));
	printf("OG string:		%s\nSubstring:		%s\n", av[1], s);
	char s2[4] = "abc";
	printf("OG string:		%s\nSubstring:		%s\n", s2, ft_substr(s2, 1, 1));
	free(s);
	return (0);
}
