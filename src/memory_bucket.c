#include "malloc.h"

static void initialize_pointers(void *ptr, t_bucket_type type);

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

static void initialize_pointers(void *ptr, t_bucket_type type)
{
	size_t	offset;

	ptr = (char*)ptr + sizeof(t_memory_bucket);
	if (type == LARGE)
	{
		((t_memory_pointer*)ptr)->size = 0;
		return;
	}
	if (type == TINY)
	{
		offset = TINY_OFFSET;
	}
	else if (type == SMALL)
	{
		offset = SMALL_OFFSET;
	}
	for (int i = 0; i < BUCKET_POINTER_COUNT; ++i)
	{
		ptr = (char*)ptr + offset;
		((t_memory_pointer*)ptr)->size = 0;
	}
}