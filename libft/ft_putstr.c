/*
**	External functions: write
*/

#include "libft.h"

void
	ft_putstr(char *s)
{
	while (*s)
		ft_putchar(*s++);
}
