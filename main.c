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
#include "stack.h"
#include "util.c"
#include "split.h"

int	main(int ac, char **av)
{
	int		i;
	int 	count;
	char	**list;
	char	***args;
	t_stack *pa;
	t_stack *pb;

	args = malloc(sizeof *args * (ac - 1));
	if (args == NULL)
		error_exit();
	i = 1;
	while (i < ac)
		args[i - 1] = ft_split(av[i], ' ');
	i = 0;
	count = 0;
	while (i < ac - 1)
	{
		list = args[i];
		while (*list)
		{
			count++;
			list++;
		}
	}
	pa = create_stack(count);
	pb = create_stack(count);

	return (0);
}
