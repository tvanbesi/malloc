/*
**	External functions: none
*/

#include "libft.h"

int
	ft_lstsize(t_list *lst)
{
	int		n;
	t_list	*current;

	n = 0;
	current = lst;
	while (current)
	{
		n++;
		current = current->next;
	}
	return (n);
}
