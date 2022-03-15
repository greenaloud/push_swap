#ifndef UTIL_H
# define UTIL_H

# define INT_MIN	-2147483648
# define INT_MAX	2147483647

int		get_arg_count(char ***list);
int		check_and_push(t_stack *pa, char ***list);
char	***get_args_list(char **argv, int size);
int		atoi_with_check(char *str, int *flag);

#endif