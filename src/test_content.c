#include "test.h"

void unit_test_content(size_t nptr, int size_ptr)
{
	char **s;
	static char c = ' ';

	s = malloc(sizeof(char *) * nptr);
	if (s == NULL || nptr == 0)
	{
		free(s);
		if (errno != 0)
		{
			ft_putnbr_fd(errno, STD_CERR);
			ft_putendl_fd(strerror(errno), STD_CERR);
		}
		return;
	}
	c = ' ';
	for (size_t i = 0; i < nptr; ++i)
	{
		s[i] = malloc(sizeof(char) * size_ptr);
		if (s[i] == NULL || size_ptr == 0)
		{
			for (size_t j = 0; j <= i; ++j)
			{
				free(s[j]);
				if (errno != 0)
				{
					ft_putnbr_fd(errno, STD_CERR);
					ft_putendl_fd(strerror(errno), STD_CERR);
				}
			}
			free(s);
			return;
		}
		memset(s[i], c, size_ptr);
		++c;
		if (c == '~')
		{
			c = ' ';
		}
		ft_putnstr(s[i], size_ptr);
		ft_putchar('\n');
	}
	for (size_t i = 0; i < nptr; ++i)
	{
		ft_putnstr(s[i], size_ptr);
		ft_putchar('\n');
	}
	for (size_t i = 0; i < nptr; ++i)
	{
		free(s[i]);
	}
	free(s);
}