#include "malloc.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#define DEC_CHARSET "0123456789"
#define TEST_CHAR_MIN 'A'
#define TEST_CHAR_MAX 'Z'

void unit_test_content(size_t nptr, size_t size_ptr);