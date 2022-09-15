#!/bin/bash

rand_limit=100000

ln -sf libft_malloc_`uname -m`_`uname -s`.so libft_malloc.so
./test.out $rand_limit > test_output_custom.txt

ln -sf libblank.so libft_malloc.so
./test.out $rand_limit > test_output_libc.txt

diff test_output_custom.txt test_output_libc.txt > test_output_diff.txt

wc test_output_libc.txt
wc test_output_custom.txt
wc test_output_diff.txt