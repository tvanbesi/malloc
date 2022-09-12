/*
**	External functions: write
*/

#include "libft.h"

void ft_putnbr_lu_base_fd(unsigned long n, char *base_charset, int fd)
{
	unsigned long	base = ft_strlen(base_charset);
	if (n >= base)
	{
		ft_putnbr_lu_base_fd(n / base, base_charset, fd);
	}
	ft_putchar_fd(base_charset[n % base], fd);
}