/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:50:28 by wocho             #+#    #+#             */
/*   Updated: 2022/02/22 18:47:23 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>

# define TOP 	0
# define BOTTOM 1

typedef struct s_stack
{
	int		*arr;
	int		size;
	int		count;
	int		top;
	int		bot;
}	t_stack;

t_stack	*create_stack(int size);
void	push(t_stack *pstack, int pos, int data);
int		pop(t_stack *pstack, int pos);
int		is_empty(t_stack *pstack);

#endif
