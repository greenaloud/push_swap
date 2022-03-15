#include "util.h"
#include <stdlib.h>
#include <unistd.h>

static int strncmp(char *str1, char *str2, int n)
{
	int	idx;

	idx = 0;
	if (n == 0)
		return (0);
	while (str1[idx] && str2[idx] && str1[idx] == str2[idx] && idx < n - 1)
		idx++;
	return (str1[idx] - str2[idx]);
}

void	error_exit()
{
	write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_SUCCESS);
}

int	atoi_with_check(const char *str, int *flag);
{
	int		sign;
	long	result;
	long	prev;

	sign = 1;
	result = 0;
	if (strncmp(str, "-2147483648", 11) == 0)
		return (INT_MIN);
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		prev = result;
		result = result * 10 + *str - '0';
		if (prev != result / 10)
			*flag = 0;
		str++;
	}
	if (str)
		*flag = 0;
	return (sign * result);
}
