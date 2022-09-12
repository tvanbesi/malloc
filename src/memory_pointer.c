#include "malloc.h"

bool	pointer_available(t_memory_pointer *ptr)
{
	return ptr->size == 0;
}