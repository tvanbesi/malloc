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