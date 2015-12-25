#include <stdio.h>
#include <string.h>

int is_palindrome(const char *s)
{
	size_t len = strlen(s);
	size_t i,j;
	if (len == 0)
		return 1;
	for (i = 0, j = len - 1; i < j; i++, j--)
		if (s[i] != s[j])
			return 0;
	return 1;
}

#define BUF_SIZE 256
int problem4(void)
{
	int i, j, largest, product;
	char buffer[BUF_SIZE];
	for (largest = 0, i = 100; i < 1000; i++) {
		for (j = 100; j < 1000; j++) {
			product = i * j;
			snprintf(buffer, BUF_SIZE, "%d", product);
			if (is_palindrome(buffer) && product > largest)
				largest = product;
		}
	}
	printf("The largest palindrome made from the product of two 3 digit numbers is %d\n", largest);
	return 0;
}

#undef BUF_SIZE
