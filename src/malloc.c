#include "malloc.h"

t_memory_bucket *g_memory_buckets;

void free(void *ptr)
{
	if (ptr == NULL)
	{
		return;
	}
	ptr = (char *)ptr - sizeof(t_memory_pointer);
	alloc_pointer(ptr, 0);
	t_memory_bucket *bucket = find_empty_bucket();
	if (bucket)
	{
		destroy_bucket(bucket);
		munmap(bucket, bucket->size);
	}
}

void *malloc(size_t size)
{
	void *ptr;

	if (size == 0)
	{
		return NULL;
	}
	if (g_memory_buckets == NULL)
	{
		init_bucket_size();
	}
	ptr = get_available_pointer(size);
	return ptr;
}

void *realloc(void *ptr, size_t size)
{
	void *new_ptr;
	size_t ptr_original_size;
	t_bucket_type original_type, new_type;

	if (ptr == NULL)
	{
		return malloc(size);
	}
	else if (size == 0)
	{
		free(ptr);
		return NULL;
	}
	ptr = (char *)ptr - sizeof(t_memory_pointer);
	ptr_original_size = ((t_memory_pointer *)ptr)->size;
	original_type = get_type_by_size(ptr_original_size);
	new_type = get_type_by_size(size);
	if (
		(original_type <= SMALL && original_type == new_type)
		|| (original_type == LARGE && new_type == LARGE && ptr_original_size >= size)
		)
	{
		alloc_pointer(ptr, size);
		ptr = (char *)ptr + sizeof(t_memory_pointer);
		return ptr;
	}
	new_ptr = malloc(size);
	if (new_ptr == NULL)
	{
		return NULL;
	}
	ft_memcpy(
		new_ptr,
		(char *)ptr + sizeof(t_memory_pointer),
		ptr_original_size - sizeof(t_memory_pointer));
	free(ptr);
	return new_ptr;
}