/*
**	External functions: malloc
*/

#include "libft.h"

char
	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*r;
	size_t	tmp;

	if (!(r = (char*)malloc(len + 1)))
		return (NULL);
	if (ft_strlen(s) > start)
	{
		tmp = ft_strlen(s + start);
		len = (len > tmp) ? tmp : len;
		ft_memcpy(r, s + start, len);
		r[len] = '\0';
	}
	else
		r[0] = '\0';
	return (r);
}
