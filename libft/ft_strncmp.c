/*
**	External functions: none
*/

#include "libft.h"

int
	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			tmp;

	tmp = n;
	n = (n > ft_strlen(s1)) ? ft_strlen(s1) : n;
	n = (n > ft_strlen(s2)) ? ft_strlen(s2) : n;
	n = (n == tmp) ? n : n + 1;
	return (ft_memcmp(s1, s2, n));
}
