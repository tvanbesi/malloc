#include "malloc.h"

static void show_pointer(void *ptr, size_t *count);
static void print_octet(size_t n);

void show_alloc_mem()
{
	void			*current_bucket;
	void			*current_pointer;
	t_memory_bucket	current_bucket_data;
	int				offset;
	static size_t	count;

	count = 0;
	current_bucket = g_memory_buckets;
	while (current_bucket)
	{
		current_bucket_data = *((t_memory_bucket*)current_bucket);
		switch (current_bucket_data.type)
		{
		case TINY:
			ft_putstr("TINY : ");
			offset = TINY_OFFSET;
			break;
		case SMALL:
			ft_putstr("SMALL : ");
			offset = SMALL_OFFSET;
			break;
		case LARGE:
			ft_putstr("LARGE : ");
			break;
		}
		ft_putnbr_lu_base_fd((unsigned long)current_bucket, HEX_CHARSET, STD_COUT);
		ft_putchar('\n');
		current_bucket = (char*)current_bucket + sizeof(t_memory_bucket);
		if (current_bucket_data.type != LARGE)
		{
			for (int i = 0; i < BUCKET_POINTER_COUNT; ++i)
			{
				current_pointer = (char*)current_bucket + (i * offset);
				if (!pointer_available(current_pointer))
				{
					show_pointer(current_pointer, &count);
				}
			}
		}
		else // current_bucket_data.type == LARGE
		{
			if (!pointer_available(current_bucket))
			{
				show_pointer(current_bucket, &count);
			}
		}
		current_bucket = current_bucket_data.next;
	}
	ft_putstr("Total : ");
	print_octet(count);
}

static void show_pointer(void *ptr, size_t *count)
{
	t_memory_pointer	*mptr = ptr;

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