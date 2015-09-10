#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

struct array {
	size_t size, alloc;
	uint64_t *data;
};
void chain_add(struct array *a, uint64_t element)
{
	if (a->alloc <= a->size) {
		if (a->alloc <= 0) {
			a->data = NULL;
			a->alloc = 1;
		}
		a->alloc *= 2;
		uint64_t *temp = realloc(a->data, sizeof *temp * a->alloc);
		assert(temp != NULL);
		a->data = temp;
	}
	a->data[a->size++] = element;
}

uint64_t chain_rule(uint64_t u)
{
	if (u % 2 == 0)
		return u / 2;
	return 3 * u + 1;
}

int chain_add_next(struct array *a)
{
	uint64_t u = chain_rule(a->data[a->size - 1]);
	if (u == 1)
		return a->size + 1;
	chain_add(a, u);
	return 0;
}

int get_chain_len(struct array *a, uint64_t num)
{
	int temp;
	a->size = 0;
	chain_add(a, num);
	while ((temp = chain_add_next(a)) == 0);
	return temp;
}
int main(void)
{
	struct array a;
	a.alloc = 0;
	uint64_t i, num = 0, max = 1000000;
	int temp, longest = 0;
	for (i = 2; i < max; i++) {
		temp = get_chain_len(&a, i);
		if (temp > longest) {
			longest = temp;
			num = i;
		}
	}
	printf("the longest chain under %" PRIu64 " is %" PRIu64 " (length %d)\n", max, num, longest);
	free(a.data);
	return 0;
}
