#include "error.h"
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

int	check_duplicate(t_stack *pa, int data)
{
	int	front;

	front = (pa->top + 1) % pa->size;
	while (front != pa->bot)
	{
		if (pa->arr[front] == data)
			return (0);
		front = (front + 1) % pa->size;
	}
	if (pa->arr[front] == data)
		return (0);
	return (1);
}

void	free_triple(char ***list)
{
	int	i;

	i = 0;
	while (list[i])
	{
		free_double(list[i]);
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
