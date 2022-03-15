#include "stack.h"
#include "command.h"
#include "push_swap.h"
#include <stdio.h>

void	push_swap(t_stack *pa, t_stack *pb)
{
	int key;
	int idx;
	int size;
	int count;

	key = 1;
	count = 1;
	while (key < pa->size - 2)
	{
		key = (key << 1) + 1;
		count++;
	}
//	printf("count: %d\n", count);
	for (int i = 0; i < count; i++) {
		key = 1 << i;
		size = pa->count;
		for (int j = 0; j < size; j++) {
			idx = (pa->top + 1) % pa->size;
			if (pa->arr[idx] & key)
				command(RA, pa, pb);
			else
				command(PB, pa, pb);
		}
		size = pb->count;
		for (int j = 0; j < size; j++)
			command(PA, pa, pb);
	}
}
