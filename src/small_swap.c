/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:53:38 by wocho             #+#    #+#             */
/*   Updated: 2022/03/17 13:53:40 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/command.h"
#include "../include/small_swap.h"

int	get_min_index(t_stack *pa)
{
	int	i;
	int	idx;
	int	min;
	int	min_idx;

	idx = (pa->top + 2) % pa->size;
	i = 1;
	min = pa->arr[(pa->top + 1) % pa->size];
	min_idx = 0;
	while (i < pa->count)
	{
		if (pa->arr[idx] < min)
		{
			min_idx = i;
			min = pa->arr[idx];
		}
		idx = (idx + 1) % pa->size;
		i++;
	}
	return (min_idx);
}

int	get_max_index(t_stack *pa)
{
	int	i;
	int	idx;
	int	max;
	int	max_idx;

	idx = (pa->top + 2) % pa->size;
	i = 1;
	max = pa->arr[(pa->top + 1) % pa->size];
	max_idx = 0;
	while (i < pa->count)
	{
		if (pa->arr[idx] > max)
		{
			max_idx = i;
			max = pa->arr[idx];
		}
		idx = (idx + 1) % pa->size;
		i++;
	}
	return (max_idx);
}

void	swap_three(t_stack *pa, t_stack *pb)
{
	int	min;
	int	max;

	min = get_min_index(pa);
	max = get_max_index(pa);
	if (min == 0 && max == 1)
	{
		command(SA, pa, pb);
		command(RA, pa, pb);
	}
	else if (min == 1 && max == 0)
		command(RA, pa, pb);
	else if (min == 1 && max == 2)
		command(SA, pa, pb);
	else if (min == 2 && max == 0)
	{
		command(SA, pa, pb);
		command(RRA, pa, pb);
	}
	else if (min == 2 && max == 1)
		command(RRA, pa, pb);
}

void	small_swap(t_stack *pa, t_stack *pb)
{
	int	min;

	while (pa->count > 3)
	{
		min = get_min_index(pa);
		if (min <= pa->count / 2)
			while (--min >= 0)
				command(RA, pa, pb);
		else
			while (++min <= pa->count)
				command(RRA, pa, pb);
		command(PB, pa, pb);
	}
	swap_three(pa, pb);
	while (pb->count)
		command(PA, pa, pb);
}
