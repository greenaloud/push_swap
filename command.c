/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:46:58 by wocho             #+#    #+#             */
/*   Updated: 2022/02/22 20:14:16 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"

static char	*p(t_stack *pa, t_stack *pb, int flag)
{
	if (flag == A)
	{
		push(pa, TOP, pop(pb, TOP));
		return ("pa\n");
	}
	else
	{
		push(pb, TOP, pop(pa, TOP));
		return ("pb\n");
	}
}

static char	*s(t_stack *pa, t_stack *pb, int flag)
{
	int	temp;

	if (flag == A)
	{
		push(pa, BOTTOM, pop(pa, TOP));
		temp = pop(pa, TOP);
		push(pa, TOP, pop(pa, BOTTOM));
		push(pa, TOP, temp);
		return ("sa\n");
	}
	else if (flag == B)
	{
		push(pb, BOTTOM, pop(pb, TOP));
		temp = pop(pb, TOP);
		push(pb, TOP, pop(pb, BOTTOM));
		push(pb, TOP, temp);
		return ("sb\n");
	}
	else
	{
		s(pa, pb, A);
		s(pa, pb, B);
		return ("ss\n");
	}
}

static char	*r(t_stack *pa, t_stack *pb, int flag)
{
	if (flag == A)
	{
		push(pa, BOTTOM, pop(pa, TOP));
		return ("ra\n");
	}
	else if (flag == B)
	{
		push(pb, BOTTOM, pop(pb, TOP));
		return ("rb\n");
	}
	else
	{
		push(pa, BOTTOM, pop(pa, TOP));
		push(pb, BOTTOM, pop(pb, TOP));
		return ("rr\n");
	}
}

static char	*rr(t_stack *pa, t_stack *pb, int flag)
{
	if (flag == A)
	{
		push(pa, TOP, pop(pa, BOTTOM));
		return ("rra\n");
	}
	else if (flag == B)
	{
		push(pb, TOP, pop(pb, BOTTOM));
		return ("rrb\n");
	}
	else
	{
		push(pa, TOP, pop(pa, BOTTOM));
		push(pb, TOP, pop(pb, BOTTOM));
		return ("rrr\n");
	}
}

char	*command(int com, t_stack *pa, t_stack *pb)
{
	if (com == PA)
		return (p(pa, pb, A));
	else if (com == PB)
		return (p(pa, pb, B));
	else if (com == SA)
		return (s(pa, pb, A));
	else if (com == SB)
		return (s(pa, pb, B));
	else if (com == SS)
		return (s(pa, pb, ALL));
	else if (com == RA)
		return (r(pa, pb, A));
	else if (com == RB)
		return (r(pa, pb, B));
	else if (com == RR)
		return (r(pa, pb, ALL));
	else if (com == RRA)
		return (rr(pa, pb, A));
	else if (com == RRB)
		return (rr(pa, pb, B));
	else
		return (rr(pa, pb, ALL));
}
