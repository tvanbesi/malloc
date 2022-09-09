/*
**	External functions: malloc
*/

#include "libft.h"

void
	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	b;

	b = count * size;
	b = b ? b : 1;
	if (!(p = malloc(b)))
		return (NULL);
	ft_bzero(p, b);
	return (p);
}
