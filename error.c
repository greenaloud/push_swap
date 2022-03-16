/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 00:57:29 by wocho             #+#    #+#             */
/*   Updated: 2022/03/16 00:58:12 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "stack.h"
#include <unistd.h>
#include <stdlib.h>

void	error_exit(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_SUCCESS);
}

void	free_double(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

void	free_triple(char ***list)
{
	int	i;

	i = 0;
	while (list[i])
	{
		free_double(list[i]);
		i++;
	}
	free(list);
}

void	free_and_exit(t_stack *pa, t_stack *pb, char ***list)
{
	free_triple(list);
	if (pa != NULL)
	{
		free(pa->arr);
		free(pa);
	}
	if (pb != NULL)
	{
		free(pb->arr);
		free(pb);
	}
	error_exit();
}
