/* ************************************************************************** */
/*                                                                            */
/*    Tester to check for SEGFAULTS in ft_lstadd_back                         */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// run with AddressSanitizer to detect leaks
int	main(void)
{
	t_list	*lst;
	lst = NULL;
	// void	*ptr1;
	// ptr1 = NULL;
	ft_lstadd_back(&lst, lst);
	lst = lst->next;
	ft_lstadd_back(&lst, lst); // this leaks
	return (0);
}
