/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:56:26 by wocho             #+#    #+#             */
/*   Updated: 2022/03/17 14:56:28 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../include/free.h"

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

void	free_stacks(t_stack *pa, t_stack *pb)
{
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
}
