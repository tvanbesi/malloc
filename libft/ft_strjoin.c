/*
**	External functions: malloc
*/

#include "libft.h"

char
	*ft_strjoin(char const *s1, char const *s2)
{
	char	*r;
	size_t	n;

	n = ft_strlen(s1) + ft_strlen(s2);
	if (!(r = (char*)ft_calloc(n + 1, sizeof(char))))
		return (NULL);
	ft_strlcat(r, s1, n + 1);
	ft_strlcat(r, s2, n + 1);
	return (r);
}
