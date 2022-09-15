#include "test.h"

static void free_array(void **ptr, size_t n);
static void show_error();
static void cycle_char(char *c);
static void debug_count(int *count);

/*
**	Unit test function to test content in allocated pointers
**
**	Note that we display the content during and after all malloc
*/
void unit_test_content(size_t nptr, size_t size_ptr)
{
	void **s;
	static char c = TEST_CHAR_MIN;
	size_t new_size;
	static int count = 0;

	s = malloc(sizeof(char *) * nptr);
	if (s == NULL || nptr == 0)
	{
		show_error();
		free(s);
		return;
	}
	// Testing malloc
	for (size_t i = 0; i < nptr; ++i)
	{
		s[i] = malloc(sizeof(char) * size_ptr);
		if (s[i] == NULL || size_ptr == 0)
		{
			show_error();
			free_array(s, i);
			return;
		}
		memset(s[i], c, size_ptr);
		cycle_char(&c);
		debug_count(&count);
		ft_putnstr(s[i], size_ptr);
		ft_putchar('\n');
	}
	for (size_t i = 0; i < nptr; ++i)
	{
		debug_count(&count);
		ft_putnstr(s[i], size_ptr);
		ft_putchar('\n');
	}
	// Testing realloc
	for (size_t i = 0; i < nptr; ++i)
	{
		new_size = (rand() % (size_ptr * 2)) + 1;
		s[i] = realloc(s[i], new_size);
		if (s[i] == NULL || new_size == 0)
		{
			show_error();
			free_array(s, nptr);
			return;
		}
		if (new_size > size_ptr)
		{
			memset(s[i], c, new_size);
			cycle_char(&c);
		}
		debug_count(&count);
		ft_putnstr(s[i], new_size);
		ft_putchar('\n');
	}
	free_array(s, nptr);
}

static void free_array(void **ptr, size_t n)
{
	for (size_t i = 0; i < n; ++i)
	{
		free(ptr[i]);
	}
	free(ptr);
	return;
}

static void show_error()
{
	if (errno != 0)
	{
		ft_putstr_fd(strerror(errno), STD_CERR);
	}
}

static void cycle_char(char *c)
{
	static char min = TEST_CHAR_MIN, max = TEST_CHAR_MAX;

	++(*c);
	if (*c > max)
	{
		*c = min;
	}
}

static void debug_count(int *count)
{
	++(*count);
	ft_putstr("test output n ");
	ft_putnbr_fd(*count, STD_COUT);
	ft_putstr(" : ");
}