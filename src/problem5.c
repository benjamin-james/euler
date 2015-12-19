#include <stdio.h>

int is_divisible_by_all_to(long l, long num)
{
	long i;
	for (i = 2; i <= num; i++)
		if (l % i != 0)
			return 0;
	return 1;
}
int main(void)
{
	long i;
	for (i = 20; is_divisible_by_all_to(i, 20) == 0; i += 20);

	printf("The smallest number divisible by all numbers from 1 to 20 is %ld\n", i);
	return 0;
}
