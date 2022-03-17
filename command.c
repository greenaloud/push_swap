#include <unistd.h>
#include "command.h"

static void	p(t_stack *pa, t_stack *pb, int flag)
{
	if (flag == A)
	{
		push(pa, TOP, pop(pb, TOP));
		write(STDOUT_FILENO, "pa\n", 3);
	}
	else
	{
		push(pb, TOP, pop(pa, TOP));
		write(STDOUT_FILENO, "pb\n", 3);
	}
}

static void	s(t_stack *pa, t_stack *pb, int flag)
{
	int	temp;

	if (flag == A)
	{
		push(pa, BOTTOM, pop(pa, TOP));
		temp = pop(pa, TOP);
		push(pa, TOP, pop(pa, BOTTOM));
		push(pa, TOP, temp);
		write(STDOUT_FILENO, "sa\n", 3);
	}
	else if (flag == B)
	{
		push(pb, BOTTOM, pop(pb, TOP));
		temp = pop(pb, TOP);
		push(pb, TOP, pop(pb, BOTTOM));
		push(pb, TOP, temp);
		write(STDOUT_FILENO, "sb\n", 3);
	}
	else
	{
		s(pa, pb, A);
		s(pa, pb, B);
		write(STDOUT_FILENO, "ss\n", 3);
	}
}

static void	r(t_stack *pa, t_stack *pb, int flag)
{
	if (flag == A)
	{
		push(pa, BOTTOM, pop(pa, TOP));
		write(STDOUT_FILENO, "ra\n", 3);
	}
	else if (flag == B)
	{
		push(pb, BOTTOM, pop(pb, TOP));
		write(STDOUT_FILENO, "rb\n", 3);
	}
	else
	{
		push(pa, BOTTOM, pop(pa, TOP));
		push(pb, BOTTOM, pop(pb, TOP));
		write(STDOUT_FILENO, "rr\n", 3);
	}
}

static void	rr(t_stack *pa, t_stack *pb, int flag)
{
	if (flag == A)
	{
		push(pa, TOP, pop(pa, BOTTOM));
		write(STDOUT_FILENO, "rra\n", 4);
	}
	else if (flag == B)
	{
		push(pb, TOP, pop(pb, BOTTOM));
		write(STDOUT_FILENO, "rrb\n", 4);
	}
	else
	{
		push(pa, TOP, pop(pa, BOTTOM));
		push(pb, TOP, pop(pb, BOTTOM));
		write(STDOUT_FILENO, "rrr\n", 4);
	}
}

void	command(int com, t_stack *pa, t_stack *pb)
{
	if (com == PA)
		(p(pa, pb, A));
	else if (com == PB)
		(p(pa, pb, B));
	else if (com == SA)
		(s(pa, pb, A));
	else if (com == SB)
		(s(pa, pb, B));
	else if (com == SS)
		(s(pa, pb, ALL));
	else if (com == RA)
		(r(pa, pb, A));
	else if (com == RB)
		(r(pa, pb, B));
	else if (com == RR)
		(r(pa, pb, ALL));
	else if (com == RRA)
		(rr(pa, pb, A));
	else if (com == RRB)
		(rr(pa, pb, B));
	else
		(rr(pa, pb, ALL));
}
