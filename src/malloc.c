#include "malloc.h"

t_memory_bucket	*g_memory_buckets;

void free(void *ptr)
{
	(void)ptr;
}

void *malloc(size_t size)
{
	(void)size;
	if (g_memory_buckets == NULL)
	{
		init_bucket_size();
	}
	return NULL;
}

void *realloc(void *ptr, size_t size)
{
	(void)ptr;
	(void)size;
	return NULL;
}