#include "malloc.h"

bool	pointer_available(t_memory_pointer *ptr)
{
	return ptr->size == 0;
}

void	alloc_pointer(t_memory_pointer *ptr, size_t size)
{
	ptr->size = size;
}