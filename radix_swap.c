#include "stack.h"
#include "command.h"
#include "radix_swap.h"

static int	get_compare_count(int size)
{
	int	num;
	int	count;

	num = 1;
	count = 1;
	while (num < size - 1)
	{
		num = (num << 1) + 1;
		count++;
	}
	return (count);
}

static int	get_min_count(t_stack *pa, int mask)
{
	int idx;
	int val;
	int count;

	count = 1;
	idx = pa->bot;
	val = pa->arr[idx] & mask;
	idx = (idx - 1 + pa->size) % pa->size;
	while (idx != pa->top)
	{
		if ((pa->arr[idx] & mask) == val)
			count++;
		else
			break ;
		idx = (idx - 1 + pa->size) % pa->size;
	}
	return (count);
}

static void	process_pa(t_stack *pa, t_stack *pb, int mask)
{
	int	i;
	int	idx;
	int	size;
	int min_count;

	min_count = get_min_count(pa, mask);
	size = pa->count - min_count;
	i = 0;
	while (i < size)
	{
		idx = (pa->top + 1) % pa->size;
		if (pa->arr[idx] & mask)
			command(RA, pa, pb);
		else
			command(PB, pa, pb);
		i++;
	}
	idx = (pa->top + 1) % pa->size;
	if (pa->arr[idx] & mask)
		while (--min_count >= 0)
			command(RA, pa, pb);
}

static void	process_pb(t_stack *pa, t_stack *pb)
{
	int	i;
	int	size;

	size = pb->count;
	i = 0;
	while (i < size)
	{
		command(PA, pa, pb);
		i++;
	}
}

static void process_pb_opt(t_stack *pa, t_stack *pb, int mask)
{
	int idx;
	int size;
	int count;

	mask <<= 1;
	count = 0;
	idx = pb->bot;
	while (idx != pb->top)
	{
		if ((pb->arr[idx] & mask) == 0)
			count++;
		else
			break ;
		idx = (idx - 1 + pb->size) % pb->size;
	}
	size = pb->count - count;
	idx = 0;
	while (idx < size)
	{
		command(PA, pa, pb);
		idx++;
	}
}

static int	check_sorted(t_stack *pa, t_stack *pb)
{
	int idx;

	idx = pb->bot;
	while (pb->count && idx != pb->top)
	{
		if (pb->arr[idx] > pb->arr[(idx - 1 + pb->size) % pb->size])
			return (0);
		idx = (idx - 1 + pb->size) % pb->size;
	}
	if (pb->arr[idx] > pa->arr[(pa->top + 1) % pa->size])
		return (0);
	idx = (pa->top + 1) % pa->size;
	while (idx != pa->bot)
	{
		if (pa->arr[idx] > pa->arr[(idx + 1) % pa->size])
			return (0);
		idx = (idx + 1) % pa->size;
	}
	return (1);
}

void	radix_swap(t_stack *pa, t_stack *pb)
{
	int	i;
	int	mask;
	int	count;

	count = get_compare_count(pa->size - 1);
	i = 0;
	while (i < count)
	{
		if (check_sorted(pa, pb))
		{
			process_pb(pa, pb);
			return ;
		}
		mask = 1 << i;
		process_pa(pa, pb, mask);
		if (i != count - 1)
			process_pb_opt(pa, pb, mask);
		else
			process_pb(pa, pb);
		i++;
	}
}
