/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 00:58:04 by wocho             #+#    #+#             */
/*   Updated: 2022/03/16 00:58:10 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include "stack.h"

# define INT_MIN	-2147483648
# define INT_MAX	2147483647

int		get_arg_count(char ***list);
int		check_duplicate(t_stack *pa, int data);
int		check_and_push(t_stack *pa, char ***list);
char	***get_args_list(char **argv, int size);
int		atoi_with_check(char *str, int *flag);

#endif
