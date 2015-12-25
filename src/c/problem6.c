#include <stdio.h>
#include <inttypes.h>

int problem6(void)
{
	uint64_t sum = 0;
	uint64_t squares = 0;
	uint64_t u;
	for (u = 1; u <= 100; u++) {
		sum += u;
		squares += u * u;
	}
	u = sum * sum - squares;
	printf("The difference between the sum of the squares of the first one hundred natural numbers and the square of the sum is %" PRIu64 "\n", u);
	return 0;
}
