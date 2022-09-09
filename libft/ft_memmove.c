/*
**	External functions: none
*/

#include "libft.h"

void
	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*cdst;
	const char	*csrc;

	cdst = dst;
	csrc = src;
	if (cdst < csrc)
		ft_memcpy(dst, src, len);
	else if (cdst > csrc)
		while (len-- > 0)
			*(cdst + len) = *(csrc + len);
	return (dst);
}
