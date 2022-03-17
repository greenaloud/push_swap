#include <stdlib.h>
#include "../include/stack.h"
#include "../include/simplify.h"
#include "../include/quick_sort.h"

static int	*create_mapper(t_stack *pa)
{
	int	i;
	int	idx;
	int	*mapper;

	mapper = malloc(sizeof(*mapper) * (pa->size - 1));
	if (mapper == NULL)
		return (NULL);
	i = 0;
	idx = (pa->top + 1) % pa->size;
	while (idx != pa->bot)
	{
		mapper[i] = pa->arr[idx];
		idx = (idx + 1) % (pa->size);
		i++;
	}
	mapper[i] = pa->arr[idx];
	quick_sort(mapper, 0, pa->size - 2);
	return (mapper);
}

static void	set_mapper_index(t_stack *pa, int idx, int *mapper)
{
	int	i;

	i = 0;
	while (i < pa->size - 1)
	{
		if (pa->arr[idx] == mapper[i])
		{
			pa->arr[idx] = i;
			break ;
		}
		i++;
	}
}

static void	map_stack(t_stack *pa, int *mapper)
{
	int	idx;

	idx = (pa->top + 1) % pa->size;
	while (idx != pa->bot)
	{
		set_mapper_index(pa, idx, mapper);
		idx = (idx + 1) % pa->size;
	}
	set_mapper_index(pa, idx, mapper);
}

void	simplify(t_stack *pa)
{
	int	*mapper;

	mapper = create_mapper(pa);
	map_stack(pa, mapper);
	free(mapper);
}