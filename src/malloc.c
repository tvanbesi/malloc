#include "malloc.h"

t_memory_bucket	*g_memory_buckets;

void free(void *ptr)
{
	alloc_pointer(ptr, 0);
}

void *malloc(size_t size)
{
	void	*ptr;

	if (g_memory_buckets == NULL)
	{
		init_bucket_size();
	}
	ptr = get_available_pointer(size);
	return ptr;
}

void *realloc(void *ptr, size_t size)
{
	(void)ptr;
	(void)size;
	return NULL;
}