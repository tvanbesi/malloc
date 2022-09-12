#include "malloc.h"

static void initialize_pointers(void *ptr, t_bucket_type type);
static bool bucket_is_empty(void *bucket);

void append_memory_bucket(t_memory_bucket **head, t_memory_bucket *add)
{
	t_memory_bucket	*current;

	if (*head == NULL)
	{
		*head = add;
		return;
	}
	current = *head;
	while (current->next)
	{
		current = current->next;
	}
	current->next = add;
}

void *create_memory_bucket(size_t size)
{
	void			*bucket_ptr;
	size_t			bucket_size;
	t_bucket_type	bucket_type;

	// Allocating the memory bucket
	if (size <= MALLOC_TINY)
	{
		bucket_size = g_bucket_size.tiny;
		bucket_type = TINY;
	}
	else if (size <= MALLOC_SMALL)
	{
		bucket_size = g_bucket_size.small;
		bucket_type = SMALL;
	}
	else // size > MALLOC_SMALL
	{
		bucket_size = nearest_multiple_of_pagesize(size + sizeof(t_memory_bucket));
		bucket_type = LARGE;
	}
	bucket_ptr = mmap(NULL, bucket_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
	if (bucket_ptr == MAP_FAILED)
	{
		return NULL;
	}
	// Initializing the memory bucket
	((t_memory_bucket*)bucket_ptr)->next = NULL;
	((t_memory_bucket*)bucket_ptr)->size = bucket_size;
	((t_memory_bucket*)bucket_ptr)->type = bucket_type;
	// Initializing the memory bucket pointers
	initialize_pointers(bucket_ptr, bucket_type);
	return bucket_ptr;
}

void destroy_bucket(t_memory_bucket *bucket_to_destroy)
{
	t_memory_bucket	*current, *previous;

	if (bucket_to_destroy == g_memory_buckets)
	{
		g_memory_buckets = g_memory_buckets->next;
		return;
	}
	previous = g_memory_buckets;
	current = g_memory_buckets->next;
	while (current)
	{
		if (current == bucket_to_destroy)
		{
			previous->next = current->next;
			return;
		}
		previous = current;
		current = current->next;
	}
}

static void initialize_pointers(void *ptr, t_bucket_type type)
{
	size_t	offset;

	ptr = (char*)ptr + sizeof(t_memory_bucket);
	switch (type)
	{
	case TINY:
		offset = TINY_OFFSET;
		break;
	case SMALL:
		offset = SMALL_OFFSET;
		break;
	case LARGE:
		((t_memory_pointer*)ptr)->size = 0;
		return;
	}
	for (int i = 0; i < BUCKET_POINTER_COUNT; ++i)
	{
		ptr = (char*)ptr + offset;
		((t_memory_pointer*)ptr)->size = 0;
	}
}

t_memory_bucket *find_empty_bucket()
{
	t_memory_bucket	*current;

	current = g_memory_buckets;
	while (current)
	{
		if (bucket_is_empty(current))
		{
			return current;
		}
		current = current->next;
	}
	return NULL;
}

static bool bucket_is_empty(void *bucket)
{
	void	*ptr;
	size_t	offset;

	ptr = (char*)bucket + sizeof(t_memory_bucket);
	switch (((t_memory_bucket*)bucket)->type)
	{
	case TINY:
		offset = TINY_OFFSET;
		break;
	case SMALL:
		offset = SMALL_OFFSET;
		break;
	case LARGE:
		return pointer_available(ptr);
		break;
	}
	for (int i = 0; i < BUCKET_POINTER_COUNT; ++i)
	{
		if (!pointer_available(ptr))
		{
			return false;
		}
		ptr = (char*)ptr + offset;
	}
	return true;
}