/*
**	External functions: none
*/

#include "libft.h"

void
	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*cdst;
	const char	*csrc;

	if (!dst && !src)
		return (NULL);
	cdst = dst;
	csrc = src;
	while (n-- > 0)
		*cdst++ = *csrc++;
	return (dst);
}
