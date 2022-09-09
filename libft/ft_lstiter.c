/*
**	External functions: none
*/

#include "libft.h"

void
	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*current;

	if (!(current = lst))
		return ;
	while (current)
	{
		f(current->content);
		current = current->next;
	}
}
