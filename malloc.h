#ifndef MALLOC_H
#define MALLOC_H

#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/resource.h>

#include "libft/libft.h"

#ifndef USE_LIBC_MALLOC

#define MALLOC_TINY		128
#define MALLOC_SMALL	256
#define TINY_OFFSET		sizeof(t_memory_pointer) + MALLOC_TINY
#define SMALL_OFFSET	sizeof(t_memory_pointer) + MALLOC_SMALL

#define BUCKET_POINTER_COUNT	100

typedef enum e_bucket_type
{
	TINY,
	SMALL,
	LARGE
}	t_bucket_type;

typedef struct s_memory_pointer
{
	size_t					size;
}	t_memory_pointer;

typedef struct s_memory_bucket
{
	struct s_memory_bucket	*next;
	size_t					size;
	t_bucket_type			type;
}	t_memory_bucket;

typedef struct s_bucket_size
{
	size_t	tiny;
	size_t	small;
}	t_bucket_size;

extern t_bucket_size	g_bucket_size;
extern t_memory_bucket	*g_memory_buckets;

void    free(void *ptr);
void    *malloc(size_t size);
void    *realloc(void *ptr, size_t size);

/*
**	Internal functions
*/

int		nearest_multiple_of_pagesize(int n);
void	init_bucket_size();
void	*create_memory_bucket(size_t size);

/*
**	Debug
*/

#define STD_ERR 2
#define PUTERR_S(msg) ft_putstr_fd(msg, STD_ERR)
#define PUTERR_N(msg) ft_putnbr_fd(msg, STD_ERR)

#endif

#endif