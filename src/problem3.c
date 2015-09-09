#include <stdio.h>
#include <math.h>
#include <inttypes.h>

#define NUMBER 600851475143L

int is_prime(uint64_t num)
{
	uint64_t u, sq = sqrt(num);
	if (num % 2 == 0)
		return 0;
	for (u = 3; u < sq; u += 2)
		if (num % u == 0)
			return 0;
	return 1;
}
int main(void)
{
	uint64_t number = NUMBER;
	uint64_t sq = sqrt(NUMBER);
	uint64_t u = 3;
	uint64_t largest = 1;
	if (number % 2 == 0) {
		number /= 2;
		largest = 2;
		sq = sqrt(number);
	}
	for (u = 3; u <= sq; u += 2) {
		if (number % u == 0 && is_prime(u)) {
			largest = u;
			number /= u;
		}
	}
	printf("The largest prime factor of %" PRIu64 " is %" PRIu64 "\n", NUMBER, largest);
	return 0;
}
