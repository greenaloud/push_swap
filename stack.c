/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:52:38 by wocho             #+#    #+#             */
/*   Updated: 2022/02/22 19:21:22 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*create_stack(int size)
{
	t_stack	*pstack;

	pstack = malloc(sizeof (t_stack));
	if (pstack == NULL)
		return (NULL);
	pstack->arr = malloc(sizeof (element) * (size + 1));
	if (pstack->arr == NULL)
	{
		free(pstack);
		return (NULL);
	}
	pstack->size = size + 1;
	pstack->top = 0;
	pstack->bot = 0;
	return (pstack);
}

void	push(t_stack *pstack, int pos, int data)
{
	if (pos == TOP)
	{
		pstack->arr[pstack->top] = data;
		pstack->top = (pstack->top - 1 + pstack->size) % (pstack->size);
	}
	else
	{
		pstack->bot = (pstack->bot + 1) % (pstack->size);
		pstack->arr[pstack->bot] = data;
	}
}

int	pop(t_stack *pstack, int pos)
{
	int	 ret;

	if (pos == TOP)
	{
		pstack->top = (pstack->top + 1) % (pstack->size);
		return (pstack->arr[pstack->top]);
	}
	else
	{
		ret = pstack->arr[pstack->bot];
		pstack->bot = (pstack->bot - 1 + pstack->size) % (pstack->size);
		return (ret);
	}
}

int	is_empty(t_stack *pstack)
{
	return (pstack->top == pstack->bot);
}
