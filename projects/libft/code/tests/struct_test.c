#include <stdlib.h>
#include <stdio.h>

typedef struct s_example
{
	void *content;
	struct s_example *next;
}	t_example;

int	main()
{
	char	string[] = "Hola :)\n";
	t_example *first;
	t_example *second;
	t_example *third;

	first = malloc(sizeof(t_example));
	second = malloc(sizeof(t_example));
	third = malloc(sizeof(t_example));

	first->next = second;
	second->next = third;
	third->next = NULL;

	third->content = string;
	printf("%s", (char *)(((first->next)->next)->content));
}
