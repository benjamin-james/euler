#include <stdio.h>
#include <inttypes.h>

uint64_t fib(uint64_t *first, uint64_t *second)
{
	uint64_t temp = *first;
	*first = *second;
	return (*second += temp);
}
int main(void)
{
	uint64_t sum = 0;
	uint64_t first = 1;
	uint64_t second = 2;

	while (fib(&first, &second) <= 4000000)
		if (second % 2 == 0)
			sum += second;
	printf("The sum of all even Fibonacci numbers not exceeding four million is %" PRIu64 "\n", sum);
	return 0;
}
