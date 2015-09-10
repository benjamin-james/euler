#include <stdio.h>
#include <math.h>
int tri_num(int n)
{
	int i, sum = 0;
	for (i = 1; i <= n; i++)
		sum += i;
	return sum;
}
/*
 * if we're halfway through the divisors
 * and we don't have half of 500 divisors
 * why continue?
 */
int num_divisors(int n, int cutoff)
{
	int i, sum, sq = sqrt(n);
	for (sum = 1, i = 2; i <= n / 2; i++) {
		if (i > sq && sum < cutoff)
			break;
		if (n % i == 0)
			sum++;
	}
	return sum;
}
#define NUM_DIVISORS 500

int main(void)
{
	int i, num, found = 0;
	for (i = 1; !found; i++)
		if (num_divisors((num = tri_num(i)), NUM_DIVISORS / 2) > NUM_DIVISORS)
			found = 1;
	printf("The first triangle number to have over %d divisors is %d with %d divisors\n", NUM_DIVISORS, num, num_divisors(num, NUM_DIVISORS / 2));
	return 0;
}
