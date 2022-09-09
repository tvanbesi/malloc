/*
**	External functions: malloc
*/

#include "libft.h"

static size_t
	get_array_final_size(int n)
{
	size_t	r;

	if (n == 0)
		return (1);
	r = (n < 0) ? 1 : 0;
	while (n)
	{
		n /= 10;
		r++;
	}
	return (r);
}

static int
	pow_of_10(size_t p)
{
	int	r;

	r = 1;
	while (p-- > 0)
		r *= 10;
	return (r);
}

char
	*ft_itoa(int n)
{
	size_t	s;
	size_t	i;
	char	*r;

	s = get_array_final_size(n);
	if (!(r = (char*)malloc(sizeof(*r) * (s + 1))))
		return (NULL);
	if (n < 0)
		*r++ = '-';
	i = (n < 0) ? s - 1 : s;
	while (i-- > 0)
	{
		*r++ = (n < 0) ? (n / pow_of_10(i)) * -1 + '0' : (n / pow_of_10(i)) + '0';
		n %= pow_of_10(i);
	}
	*r = '\0';
	return (r - s);
}
