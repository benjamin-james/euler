#include <stdio.h>
#include <inttypes.h>

#define MAX_NUM 1000000

int main(void)
{
	uint64_t longest, longest_i, i, num, len, max = MAX_NUM;
	for (longest = longest_i = 0, i = 2; i < max; i++) {
		for (len = 0, num = i; num != 1; len++) {
			if (num % 2 == 0)
				num /= 2;
			else
				num = num * 3 + 1;
		}
		if (len > longest) {
			longest = len;
			longest_i = i;
		}
	}
	printf("The longest chain under %" PRIu64 " is %" PRIu64 " (length %" PRIu64 ")\n", max, longest_i, longest);
	return 0;
}
