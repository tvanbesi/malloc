/*
**	External functions: none
*/

#include "libft.h"

size_t
	ft_strlen(const char *s)
{
	size_t r;

	r = 0;
	while (*s++)
		r++;
	return (r);
}
