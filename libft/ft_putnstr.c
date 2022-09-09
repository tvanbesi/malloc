/*
**	External functions: write
*/

#include "libft.h"

void
	ft_putnstr(char *s, size_t n)
{
	while (*s && n-- > 0)
		ft_putchar(*s++);
}
