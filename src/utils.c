#include "malloc.h"

/*
**	This util function returns the nearest multiple of getpagesize of n,
**	rounded up.
*/
int nearest_multiple_of_pagesize(int n)
{
	int page_offset;

	page_offset = n % getpagesize();
	if (page_offset != 0)
	{
		n = n - page_offset + getpagesize();
	}
	return n;
}

t_bucket_type get_type_by_size(size_t size)
{
	if (size < MALLOC_TINY)
	{
		return TINY;
	}
	else if (size < MALLOC_SMALL)
	{
		return SMALL;
	}
	else
	{
		return LARGE;
	}
}