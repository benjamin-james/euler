#include <stdio.h>
#include <math.h>

int is_prime(int num)
{
	int i, sq = sqrt(num) + 1;
	if (num % 2 == 0)
		return 0;
	for (i = 3; i < sq; i += 2)
		if (num % i == 0)
			return 0;
	return 1;
}
int main(void)
{
	int i, prime_num = 1;
	for (i = 2; prime_num < 10001; i++) {
		if (is_prime(i))
			prime_num++;
	}
	printf("The %dth prime is %d\n", 10001, i - 1);
	return 0;
}
