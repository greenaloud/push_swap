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
