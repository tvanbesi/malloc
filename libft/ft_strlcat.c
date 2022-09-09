/*
**	External functions: none
*/

#include "libft.h"

size_t
	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	lsrc;
	size_t	ldst;

	lsrc = ft_strlen(src);
	ldst = ft_strlen(dst);
	ldst = ldst > dstsize ? dstsize : ldst;
	if (ldst + 1 >= dstsize)
		return (ldst + lsrc);
	if (ldst + lsrc + 1 < dstsize)
		ft_memcpy(dst + ldst, src, lsrc + 1);
	else if (dstsize)
	{
		ft_memcpy(dst + ldst, src, dstsize - ldst - 1);
		dst[dstsize - 1] = '\0';
	}
	return (lsrc + ldst);
}
