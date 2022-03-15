/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 00:57:40 by wocho             #+#    #+#             */
/*   Updated: 2022/03/16 00:58:12 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static int	divide(int *arr, int s, int e)
{
	int	lt;
	int	rt;
	int	pivot;

	lt = s + 1;
	rt = e;
	pivot = arr[s];
	while (lt <= rt)
	{
		while (arr[lt] <= pivot && lt <= e)
			lt++;
		while (arr[rt] >= pivot && rt >= s + 1)
			rt--;
		if (lt <= rt)
			swap(&(arr[lt]), &(arr[rt]));
	}
	swap(&(arr[s]), &(arr[rt]));
	return (rt);
}

void	quick_sort(int *arr, int s, int e)
{
	int	pivot;

	if (s >= e)
		return ;
	pivot = divide(arr, s, e);
	quick_sort(arr, s, pivot - 1);
	quick_sort(arr, pivot + 1, e);
}
