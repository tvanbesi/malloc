/*
**	External functions: malloc
*/

#include "libft.h"

t_list
	*ft_lstnew(void *content)
{
	t_list	*r;

	if (!(r = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	r->content = content;
	r->next = NULL;
	return (r);
}
