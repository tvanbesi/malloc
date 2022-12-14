#ifndef MALLOC_H
#define MALLOC_H

#include <sys/mman.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <stdbool.h>

#include "libft.h"

#define STD_CIN 0
#define STD_COUT 1
#define STD_CERR 2
#define HEX_CHARSET "0123456789ABCDEF"

#define MALLOC_TINY 128
#define MALLOC_SMALL 256
#define TINY_OFFSET sizeof(t_memory_pointer) + MALLOC_TINY
#define SMALL_OFFSET sizeof(t_memory_pointer) + MALLOC_SMALL

#define BUCKET_POINTER_COUNT 100

typedef enum e_bucket_type
{
	TINY = 1,
	SMALL = 2,
	LARGE = 3
} t_bucket_type;

typedef struct s_memory_pointer
{
	size_t size;
} t_memory_pointer;

typedef struct s_memory_bucket
{
	struct s_memory_bucket *next;
	size_t size;
	t_bucket_type type;
} t_memory_bucket;

typedef struct s_bucket_size
{
	size_t tiny;
	size_t small;
} t_bucket_size;

extern t_bucket_size g_bucket_size;
extern t_memory_bucket *g_memory_buckets;

void free(void *ptr);
void *malloc(size_t size);
void *realloc(void *ptr, size_t size);
void show_alloc_mem();

/*
**	Internal functions
*/

void *create_memory_bucket(size_t size);
t_memory_bucket *find_empty_bucket();
t_bucket_type get_type_by_size(size_t size);
void append_memory_bucket(t_memory_bucket **head, t_memory_bucket *add);
void destroy_bucket(t_memory_bucket *bucket_to_destroy);

void *get_available_pointer(size_t size);
bool pointer_available(t_memory_pointer *ptr);
void alloc_pointer(t_memory_pointer *ptr, size_t size);

void init_bucket_size();
int nearest_multiple_of_pagesize(int n);

#endif