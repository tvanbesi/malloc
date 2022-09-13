ln -sf libft_malloc_`uname -m`_`uname -s`.so libft_malloc.so
./test.out > test_output_custom.txt
ln -sf libblank.so libft_malloc.so
./test.out > test_output_libc.txt
diff test_output_custom.txt test_output_libc.txt > test_output_diff.txt
wc -c test_output_diff.txt