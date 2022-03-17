#ifndef STACK_H
# define STACK_H

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
