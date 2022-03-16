#include "stack.h"
#include "command.h"
#include "quick_swap.h"

static void	swap_back(t_stack *pa, t_stack *pb, int start, int end)
{
	int idx;
	int loop;
	int pivot;

	if (start == end)
		command(PA, pa, pb);
	idx = (pb->top + 1) % pb->top;
	pivot = start + (end - start) / 2;
	loop = end - start + 1;
	while (--loop >= 0)
	{
		if (pb->arr[idx] <= pivot)
			command(RB, pa, pb);
	}


}

void	quick_swap(t_stack *pa, t_stack *pb, int start, int end)
{
	int idx;
	int loop;
	int pivot;

	if (pa->count < 2)
		return ;
	idx = (pa->top + 1) % pa->size;
	pivot = start + (end - start) / 2;
	loop = pa->count;
	while (--loop >= 0)
	{
		if (idx <= pivot)
			command(PB, pa, pb);
		else
			command(RA, pa, pb);
	}
	quick_swap(pa, pb, pivot + 1, end);
	swap_back(pa, pb, s, pivot);
}
