#include "error.h"
#include "util.h"
#include "split.h"
#include "stack.h"
#include <stdlib.h>

int	get_arg_count(char ***list)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (list[i])
	{
		j = 0;
		while (list[i][j])
		{
			count++;
			j++;
		}
		i++;
	}
	return (count);
}

char	***get_args_list(char **argv, int size)
{
	int		i;
	char	***list;

	list = malloc(sizeof (*list) * (size + 1));
	if (list == NULL)
		error_exit();
	list[size] = NULL;
	i = 0;
	while (*argv)
	{
		list[i] = ft_split(*argv, ' ');
		if (list[i] == NULL)
		{
			while (--i >= 0)
				free_double(list[i]);
			free(list);
			error_exit();
		}
		i++;
		argv++;
	}
	return (list);
}

int	check_and_push(t_stack *pa, char ***list)
{
	int	i;
	int	j;
	int	data;
	int	flag;

	i = 0;
	while (list[i])
	{
		j = 0;
		while (list[i][j])
		{
			flag = 1;
			data = atoi_with_check(list[i][j], &flag);
			if (!flag || !check_duplicate(pa, data))
				return (0);
			push(pa, BOTTOM, data);
			j++;
		}
		i++;
	}
	return (1);
}

int	atoi_with_check(char *str, int *flag)
{
	int		sign;
	int		digits;
	long	result;

	sign = 1;
	result = 0;
	digits = 0;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str == '0')
		str++;
	while ('0' <= *str && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
		digits++;
	}
	result *= sign;
	if (*str || digits > 10 || result > INT_MAX || result < INT_MIN)
		*flag = 0;
	return ((int)result);
}
