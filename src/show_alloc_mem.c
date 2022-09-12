#include "malloc.h"

static void show_pointer(void *ptr);

void show_alloc_mem()
{
	void			*current_bucket;
	void			*current_pointer;
	t_memory_bucket	current_bucket_data;
	int				offset;

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
					show_pointer(current_pointer);
				}
			}
		}
		else // current_bucket_data.type == LARGE
		{
			if (!pointer_available(current_bucket))
			{
				show_pointer(current_bucket);
			}
		}
		current_bucket = current_bucket_data.next;
	}
}

static void show_pointer(void *ptr)
{
	t_memory_pointer	*mptr = ptr;

	ft_putnbr_lu_base_fd((unsigned long)ptr, HEX_CHARSET, STD_COUT);
	ft_putstr(" - ");
	ft_putnbr_lu_base_fd((unsigned long)ptr + mptr->size, HEX_CHARSET, STD_COUT);
	ft_putstr(" : ");
	ft_putnbr_fd(mptr->size, STD_COUT);
	ft_putstr_fd(" octet", STD_COUT);
	if (mptr->size > 1)
		ft_putendl_fd("s", STD_COUT);
	else
		ft_putchar('\n');
}