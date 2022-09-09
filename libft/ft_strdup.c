/*
**	External functions: malloc
*/

#include "libft.h"

char
	*ft_strdup(const char *s1)
{
	size_t	s;
	char	*r;

	s = ft_strlen(s1);
	if (!(r = (char*)malloc(s + 1)))
		return (NULL);
	ft_strlcpy(r, s1, s + 1);
	return (r);
}
