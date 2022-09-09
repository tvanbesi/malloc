/*
**	External functions: none
*/

#include "libft.h"

void
	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned const char	*cs;
	unsigned char		uc;

	cs = s;
	uc = (unsigned char)c;
	while (n-- > 0)
	{
		if (*cs == uc)
			return (void*)cs;
		cs++;
	}
	return (NULL);
}
