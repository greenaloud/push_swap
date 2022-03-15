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
#include "command.h"
#include "error.h"
#include "stack.h"
#include "util.h"

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

int	main(int argc, char **argv)
{
	char	***list;
	t_stack	*pa;
	t_stack	*pb;

	list = get_args_list(argv + 1, argc - 1);
	if (!init_stacks(&pa, &pb, list))
		free_and_exit(pa, pb, list);
	if (!check_and_push(pa, list))
		free_and_exit(pa, pb, list);
	free_triple(list);
	push_swap(pa, pb);

	// 스택 확인용 코드
	int idx = (pa->top + 1) % pa->size;
	while (idx != pa->bot)
	{
		printf("%d\n", pa->arr[idx]);
		idx = (idx + 1) % (pa->size);
	}
	printf("%d\n", pa->arr[idx]);
	// 주석 사이 코드 삭제할 것
	return (0);
}
