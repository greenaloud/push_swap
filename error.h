#ifndef ERROR_H
# define ERROR_H

void	error_exit(void);
void	free_double(char **ptr);
int		check_duplicate(t_stack *pa, int data);
void	free_triple(char ***list);
void	free_and_exit(t_stack *pa, t_stack *pb, char ***list);

#endif
