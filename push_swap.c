/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 00:57:38 by wocho             #+#    #+#             */
/*   Updated: 2022/03/16 00:58:12 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "command.h"
#include "push_swap.h"

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

static void	process_pa(t_stack *pa, t_stack *pb, int mask)
{
	int	i;
	int	idx;
	int	size;

	size = pa->count;
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

void	push_swap(t_stack *pa, t_stack *pb)
{
	int	i;
	int	mask;
	int	count;

	count = get_compare_count(pa->size - 1);
	i = 0;
	while (i < count)
	{
		mask = 1 << i;
		process_pa(pa, pb, mask);
		process_pb(pa, pb);
		i++;
	}
}
