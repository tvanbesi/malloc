#include "malloc.h"

static void show_pointer(void *ptr, size_t *count);
static void print_octet(size_t n);
static void show_pointers_in_bucket(void *bucket, size_t *count);
static void show_bucket_data(t_memory_bucket *bucket, int *offset);

void show_alloc_mem()
{
	t_memory_bucket *current;
	static size_t count;

	count = 0;
	current = g_memory_buckets;
	while (current)
	{
		show_pointers_in_bucket(current, &count);
		current = current->next;
	}
}

static void show_pointers_in_bucket(void *bucket, size_t *count)
{
	int offset;
	void *ptr;
	t_memory_bucket bucket_data;

	show_bucket_data(bucket, &offset);
	bucket_data = *(t_memory_bucket *)bucket;
	ptr = (char *)bucket + sizeof(t_memory_bucket);
	if (bucket_data.type != LARGE)
	{
		for (int i = 0; i < BUCKET_POINTER_COUNT; ++i)
		{
			if (!pointer_available(ptr))
			{
				show_pointer(ptr, count);
			}
			ptr = (char *)ptr + offset;
		}
	}
	else // bucket_data.type == LARGE
	{
		if (!pointer_available(ptr))
		{
			show_pointer(ptr, count);
		}
	}
	ft_putstr("Total : ");
	print_octet(*count);
}

static void show_bucket_data(t_memory_bucket *bucket, int *offset)
{
	switch (bucket->type)
	{
	case TINY:
		ft_putstr("TINY : ");
		*offset = TINY_OFFSET;
		break;
	case SMALL:
		ft_putstr("SMALL : ");
		*offset = SMALL_OFFSET;
		break;
	case LARGE:
		ft_putstr("LARGE : ");
		break;
	}
	ft_putnbr_lu_base_fd((unsigned long)bucket, HEX_CHARSET, STD_COUT);
	ft_putchar('\n');
}

static void show_pointer(void *ptr, size_t *count)
{
	t_memory_pointer *mptr = ptr;

	ptr = (char *)ptr + sizeof(t_memory_pointer);
	ft_putnbr_lu_base_fd((unsigned long)ptr, HEX_CHARSET, STD_COUT);
	ft_putstr(" - ");
	ft_putnbr_lu_base_fd((unsigned long)ptr + mptr->size, HEX_CHARSET, STD_COUT);
	ft_putstr(" : ");
	print_octet(mptr->size);
	*count += mptr->size;
}

static void print_octet(size_t n)
{
	ft_putnbr_fd(n, STD_COUT);
	ft_putstr(" octet");
	if (n > 1)
		ft_putendl_fd("s", STD_COUT);
	else
		ft_putchar('\n');
}