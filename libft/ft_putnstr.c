/*
**	External functions: write
*/

#include "libft.h"

void
	ft_putnstr(char *s, size_t n)
{
	write(1, s, n);
}
