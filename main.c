/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:49:03 by wocho             #+#    #+#             */
/*   Updated: 2022/02/22 20:17:34 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "error.h"
#include "stack.h"
#include "util.h"
#include "push_swap.h"

static int	init_stacks(t_stack **pa, t_stack **pb, char ***list)
{
	int	count;

	count = get_arg_count(list);
	*pa = create_stack(count);
	*pb = create_stack(count);
	if (*pa == NULL || *pb == NULL)
		return (0);
	return (1);
}

static void	get_longest_ordered(t_stack *pa, t_stack *pb)
{
	int	loop, j;
	int idx_count[2];
	int count;
	int arr_size;

	arr_size = pa->size - 1;
	idx_count[0] = (pa->top + 1) % pa->size;
	idx_count[1] = 1;
	loop = 0;
	while (loop < arr_size) {
		int idx = (pa->top + 1 + loop) % pa->size;
		printf("starts with %d: ", pa->arr[idx]);
		count = 1;
		j = 0;
		while (j < arr_size - 1) {
			if ((pa->arr)[idx] > (pa->arr)[(idx + 1) % pa->size])
				break;
			count++;
			idx = (idx + 1) % pa->size;
			j++;
		}
		printf("longest ordered count: %d\n", count);
		if (idx_count[1] < count) {
			idx_count[1] = count;
			idx_count[0] = (pa->top + 1 + loop) % pa->size;
		}
		loop++;
	}
	printf("longest ordered list starts with: [%d] -> %d, count: %d\n", idx_count[0], (pa->arr)[idx_count[0]], idx_count[1]);
}

static void	merge(int *arr, int s, int m, int e)
{
	int li;
	int ri;
	int idx;
	int	*left;
	int *right;

	left = malloc(sizeof (*left) * (m - s + 1));
	right = malloc(sizeof (*right) * (e - m));
	li = -1;
	while (++li < m - s + 1)
		left[li] = arr[s + li];
	ri = -1;
	while (++ri < e - m)
		right[ri] = arr[m + 1 + ri];
	idx = 0;
	li = 0;
	ri = 0;
	while (li < m - s + 1 && ri < e - m)
	{
		if (left[li] <= right[ri])
			arr[s + idx++] = left[li++];
		else
			arr[s + idx++] = right[ri++];
	}
	if (li == m - s + 1)
		while (ri < e - m)
			arr[s + idx++] = right[ri++];
	else
		while (li < m - s + 1)
			arr[s + idx++] = left[li++];
	free(left);
	free(right);
}

static void	merge_sort(int *arr, int s, int e)
{
	int mid;
	if (s >= e)
		return ;
	mid = s + (e - s) / 2;
	merge_sort(arr, s, mid);
	merge_sort(arr, mid + 1, e);
	merge(arr, s, mid, e);
}

int	main(int argc, char **argv)
{
	char	***list;
	t_stack	*pa;
	t_stack	*pb;

	if (argc == 1)
		return (0);
	list = get_args_list(argv + 1, argc - 1);
	if (!init_stacks(&pa, &pb, list))
		free_and_exit(pa, pb, list);
	if (!check_and_push(pa, list))
		free_and_exit(pa, pb, list);
	free_triple(list);

	int	*mapper;
	mapper = malloc(sizeof(*mapper) * (pa->size - 1));
	int i = 0;
	int idx = (pa->top + 1) % pa->size;
	while (idx != pa->bot)
	{
		mapper[i] = pa->arr[idx];
//		printf("%d\n", pa->arr[idx]);
		idx = (idx + 1) % (pa->size);
		i++;
	}
	mapper[i] = pa->arr[idx];
//	printf("%d\n", pa->arr[idx]);
//	printf("after SORT\n");
	merge_sort(mapper, 0, pa->size - 2);
	for (int j = 0; j < pa->size - 1; ++j) {
//		printf("%d\n", mapper[j]);
	}

//	j --> mapper 용 index
	idx = (pa->top + 1) % pa->size;
	while (idx != pa->bot)
	{
		for (int j = 0; j < pa->size - 1; ++j)
		{
			if (pa->arr[idx] == mapper[j])
			{
				pa->arr[idx] = j;
				break ;
			}
		}
		idx = (idx + 1) % (pa->size);
	}
	for (int j = 0; j < pa->size - 1; ++j)
		if (pa->arr[idx] == mapper[j])
			pa->arr[idx] = j;
	idx = (pa->top + 1) % pa->size;
	while (idx != pa->bot)
	{
//		printf("%d\n", pa->arr[idx]);
		idx = (idx + 1) % (pa->size);
	}
//	printf("%d\n", pa->arr[idx]);
	// 주석 사이 코드 삭제할 것
	push_swap(pa, pb);
	idx = (pa->top + 1) % pa->size;
	while (idx != pa->bot)
	{
//		printf("%d\n", pa->arr[idx]);
		idx = (idx + 1) % (pa->size);
	}
//	printf("%d\n", pa->arr[idx]);
	return (0);
}
