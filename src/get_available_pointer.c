#include "malloc.h"

static void *find_available_pointer_in_memory(t_bucket_type type);
static void *find_available_pointer_in_bucket(void *bucket_ptr, t_bucket_type type);

/*
**	Return a pointer to available memory of adequate size
*/
void *get_available_pointer(size_t size)
{
	void			*ptr;
	t_bucket_type	type;

	type = get_type_by_size(size);
	ptr = find_available_pointer_in_memory(type);
	// Create new bucket if no available pointer was found
	if (ptr == NULL)
	{
		ptr = create_memory_bucket(size);
		if (ptr == NULL)
		{
			return NULL;
		}
		append_memory_bucket(&g_memory_buckets, ptr);
		ptr = (char*)ptr + sizeof(t_memory_bucket);
	}
	alloc_pointer(ptr, size);
	return ptr;
}

/*
**	Look for available memory in allocated memory buckets
**
**	return:
**		- NULL if no available memory was found
**		- a pointer to available memory otherwise
*/
static void *find_available_pointer_in_memory(t_bucket_type type)
{
	t_memory_bucket	*current;
	void			*ptr;

	current = g_memory_buckets;
	while (current)
	{
		if (current->type == type)
		{
			ptr = find_available_pointer_in_bucket(current, type);
			if (ptr)
			{
				return ptr;
			}
		}
		current = current->next;
	}
	return NULL;
}

/*
**	Look for an available pointer in a memory bucket
*/
static void *find_available_pointer_in_bucket(void *bucket_ptr, t_bucket_type type)
{
	int offset;

	switch (type)
	{
	case TINY:
		offset = TINY_OFFSET;
		break;
	case SMALL:
		offset = SMALL_OFFSET;
		break;
	default:
		return NULL;
	}
	bucket_ptr = (char*)bucket_ptr + sizeof(t_memory_bucket);
	for (int i = 0; i < BUCKET_POINTER_COUNT; ++i)
	{
		if (pointer_available(bucket_ptr))
		{
			return bucket_ptr;
		}
		bucket_ptr = (char*)bucket_ptr + offset;
	}
	return NULL;
}