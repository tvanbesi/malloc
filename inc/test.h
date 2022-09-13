#include "malloc.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#define DEC_CHARSET "0123456789"

void unit_test_content(size_t nptr, int size_ptr);