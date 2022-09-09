/*
**	External functions: none
*/

#include "libft.h"

char
	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*ph;
	size_t	sn;

	ph = (char*)haystack;
	sn = ft_strlen(needle);
	if (!*needle)
		return (ph);
	while (len-- > 0 && *ph)
	{
		if (*ph == *needle && sn <= len + 1)
			if (!ft_strncmp(ph, needle, sn))
				return (ph);
		ph++;
	}
	return (NULL);
}
