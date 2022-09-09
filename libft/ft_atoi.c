/*
**	External functions: none
*/

#include "libft.h"

int
	ft_atoi(const char *str)
{
	int s;
	int r;

	s = 1;
	r = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			s = -1;
	while (ft_isdigit(*str))
		r = r * 10 + (*str++ - '0');
	return (r * s);
}
