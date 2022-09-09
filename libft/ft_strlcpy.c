/*
**	External functions: none
*/

#include "libft.h"

size_t
	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	lsrc;

	lsrc = ft_strlen(src);
	if (lsrc + 1 < dstsize)
		ft_memcpy(dst, src, lsrc + 1);
	else if (dstsize)
	{
		ft_memcpy(dst, src, dstsize - 1);
		dst[dstsize - 1] = '\0';
	}
	return (lsrc);
}
