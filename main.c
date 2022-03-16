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
#include "quick_sort.h"
#include "util.h"
#include "error.h"
#include "stack.h"
#include "radix_swap.h"

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

static int	*create_mapper(t_stack *pa)
{
	int	i;
	int	idx;
	int	*mapper;

	mapper = malloc(sizeof(*mapper) * (pa->size - 1));
	if (mapper == NULL)
		return (NULL);
	i = 0;
	idx = (pa->top + 1) % pa->size;
	while (idx != pa->bot)
	{
		mapper[i] = pa->arr[idx];
		idx = (idx + 1) % (pa->size);
		i++;
	}
	mapper[i] = pa->arr[idx];
	quick_sort(mapper, 0, pa->size - 2);
	return (mapper);
}

static void	set_mapper_index(t_stack *pa, int idx, int *mapper)
{
	int	i;

	i = 0;
	while (i < pa->size - 1)
	{
		if (pa->arr[idx] == mapper[i])
		{
			pa->arr[idx] = i;
			break ;
		}
		i++;
	}
}

static void	map_stack(t_stack *pa, int *mapper)
{
	int	idx;

	idx = (pa->top + 1) % pa->size;
	while (idx != pa->bot)
	{
		set_mapper_index(pa, idx, mapper);
		idx = (idx + 1) % pa->size;
	}
	set_mapper_index(pa, idx, mapper);
}

int	main(int argc, char **argv)
{
	int		*mapper;
	char	***list;
	t_stack	*pa;
	t_stack	*pb;

	if (argc == 1)
		return (0);
//	printf("ARG: %s\n", argv[1]);
	list = get_args_list(argv + 1, argc - 1);
	if (!init_stacks(&pa, &pb, list))
		free_and_exit(pa, pb, list);
	if (!check_and_push(pa, list))
		free_and_exit(pa, pb, list);
	free_triple(list);
	mapper = create_mapper(pa);
	map_stack(pa, mapper);
	radix_swap(pa, pb);
	return (0);
}
