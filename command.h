#ifndef COMMAND_H
# define COMMAND_H

# include "stack.h"

# define A		0
# define B		1
# define ALL	2

# define PA		0
# define PB		1
# define SA		2
# define SB		3
# define SS		4
# define RA		5
# define RB		6
# define RR		7
# define RRA	8
# define RRB	9
# define RRR	10

void	command(int com, t_stack *pa, t_stack *pb);

#endif
