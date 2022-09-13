#include "test.h"

int main()
{
	int limit, n, r1, r2;
	unsigned int seed;

	n = 10000;
	limit = 10000;
	seed = 42;
	srand(seed);
	(void)seed;

	for (int i = 0; i < n; ++i)
	{
		r1 = (rand() % limit) + 1;
		r2 = (rand() % r1) + 1;
		unit_test_content(r1 / r2, r1 % r2);
	}
	return 0;
}