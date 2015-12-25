#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int array_add(long *array, int element, int *size, int *alloc)
{
	if (*size == *alloc) {
		*alloc *= 2;
		long *temp = realloc(array, *alloc * sizeof *array);
		if (!temp) {
			fprintf(stderr, "Couldn't realloc\n");
			exit(EXIT_FAILURE);
		}
		array = temp;
	}
	array[*size] = element;
	return (*size)++;
}
int is_prime_list(long *list, int num, int size)
{
	int i;
	long sq = sqrt(num);
	for (i = 0; i < size; i++) {
		if (num % list[i] == 0)
			return 0;
		if (sq + 1 > num)
			break;
	}
	return 1;
}
int add_next_prime_under(long *list, int *size, int *alloc, int num)
{
	if (*size == 0)
		return array_add(list, 2, size, alloc);
	if (*size == 1)
		return array_add(list, 3, size, alloc);
	int i;
	for (i = 5; i < num; i += 2) {
		if (is_prime_list(list, i, *size)) {
			return array_add(list, i, size, alloc);
		}
	}
	return -1;
}

long array_sum(long *array, int size)
{
	long sum = 0;
	int i;
	for (i = 0; i < size; i++) {
		sum += array[i];
	}
	return sum;
}
int problem10(void)
{
	int num_primes = 2000000;
	int *primes = malloc(sizeof *primes * num_primes);
	int i, j, sr = sqrt(num_primes) + 1;
	long sum;
	for (i = 0; i < num_primes; i++)
		primes[i] = i;
	for (i = 2; i < sr;) {
		for (j = i + 1; j < num_primes; j++) {
			if (primes[j] % i == 0) {
				primes[j] = 0;
			}
		}
		for (j = i + 1; j < num_primes; j++) {
			if (primes[j] != 0) {
				i = j;
				break;
			}
		}
	}
	for (sum = 0, i = 2; i < num_primes; i++) {
		if (primes[i] != 0) {
			sum += primes[i];
		}
	}
	printf("The sum of the all primes under %d is %ld\n", num_primes, sum);
	free(primes);
	return 0;
}
