#ifndef MALLOC_H
#define MALLOC_H

#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/resource.h>

#include "libft/libft.h"

#ifndef MAP_ANONYMOUS
#define MAP_ANONYMOUS 0x20
#endif

#ifndef USE_LIBC_MALLOC
void    free(void *ptr);
void    *malloc(size_t size);
void    *realloc(void *ptr, size_t size);
#endif

#endif