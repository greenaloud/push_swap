/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:49:03 by wocho             #+#    #+#             */
/*   Updated: 2022/03/17 13:52:36 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "../include/stack.h"
#include "../include/free.h"
#include "../include/util.h"
#include "../include/error.h"
#include "../include/simplify.h"
#include "../include/small_swap.h"
#include "../include/radix_swap.h"

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

	if (argc == 1)
		return (0);
	list = get_args_list(argv + 1, argc - 1);
	if (!init_stacks(&pa, &pb, list))
		free_and_exit(pa, pb, list);
	if (!check_and_push(pa, list))
		free_and_exit(pa, pb, list);
	free_triple(list);
	simplify(pa);
	if (pa->count <= 50)
		small_swap(pa, pb);
	else
		radix_swap(pa, pb);
	free_stacks(pa, pb);
	return (0);
}
