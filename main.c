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
#include "command.h"
#include "stack.h"
#include "ft_atoi.c"

int	main(int ac, char **av)
{
	int		i;
	t_stack	*pa;
	t_stack *pb;

	pa = create_stack(ac - 1);
	pb = create_stack(ac - 1);
	i = ac - 1;
	while (i > 0)
	{
		push(pa, TOP, ft_atoi(av[i]));
		i--;
	}
	
	command(PB, pa, pb);
	command(PB, pa, pb);
	command(SS, pa, pb);
	command(RRA, pa, pb);
	command(RB, pa, pb);

	while (is_empty(pa) != 1)
		printf("%d\n", pop(pa, TOP));
	printf("=====PB====\n");
	while (is_empty(pb) != 1)
		printf("%d\n", pop(pb, TOP));
	return (0);
}
