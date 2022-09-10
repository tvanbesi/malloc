#include "malloc.h"

t_bucket_size   g_bucket_size;

/*
**  Initializes the global variable g_bucket_size
**
**  g_bucket_size.tiny is a multiple of getpagesize() with enough space
**  to store BUCKET_POINTER_COUNT pointers of MALLOC_TINY bytes of
**  available data. g_bucket_size.small is the same but with
**  MALLOC_SMALL.
*/
void init_bucket_size()
{
    int size, page_offset;
    int mbucket_size, mpointer_size;

    mbucket_size = sizeof(t_memory_bucket);
    mpointer_size = sizeof(t_memory_pointer);

    size = (mpointer_size + MALLOC_TINY);
    size *= BUCKET_POINTER_COUNT;
    size += mbucket_size;
    page_offset = size % getpagesize();
    if (page_offset != 0)
    {
        size = size - page_offset + getpagesize();
    }
    g_bucket_size.tiny = size;

    size = (mpointer_size + MALLOC_SMALL);
    size *= BUCKET_POINTER_COUNT;
    size += mbucket_size;
    page_offset = size % getpagesize();
    if (page_offset != 0)
    {
        size = size - page_offset + getpagesize();
    }
    g_bucket_size.small = size;
}