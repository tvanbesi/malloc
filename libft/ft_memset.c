/*
**	External functions: none
*/

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*uc;

	uc = b;
	while (len-- > 0)
		*uc++ = c;
	return (b);
}
