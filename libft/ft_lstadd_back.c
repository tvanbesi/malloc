/*
**	External functions: none
*/

#include "libft.h"

void
	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*last;

	if (!(last = ft_lstlast(*alst)))
		*alst = new;
	else
		last->next = new;
}
