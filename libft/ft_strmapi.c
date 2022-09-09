/*
**	External functions: malloc
*/

#include "libft.h"

char
	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	size_t			l;
	char			*r;

	l = ft_strlen(s);
	if (!(r = (char*)malloc(l + 1)))
		return (NULL);
	i = 0;
	while (i < l)
		*r++ = f(i++, *s++);
	*r = '\0';
	return (r - l);
}
