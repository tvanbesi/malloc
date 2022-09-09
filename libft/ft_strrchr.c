/*
**	External functions: none
*/

#include "libft.h"

char
	*ft_strrchr(const char *s, int c)
{
	const char	*ps;
	const char	*tmp;

	if (c == '\0')
		return (ft_strchr(s, c));
	ps = NULL;
	while ((tmp = ft_strchr(s, c)))
	{
		ps = tmp;
		s = ps + 1;
	}
	return ((char*)ps);
}
