/*
**	External functions: none
*/

#include "libft.h"

void
	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*cdst;
	unsigned const char	*csrc;
	unsigned char		uc;

	cdst = dst;
	csrc = src;
	uc = (unsigned char)c;
	while (n-- > 0)
	{
		*cdst++ = *csrc;
		if (*csrc++ == uc)
			return ((void*)cdst);
	}
	return (NULL);
}
