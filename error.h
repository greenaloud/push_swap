/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 00:57:50 by wocho             #+#    #+#             */
/*   Updated: 2022/03/16 00:58:12 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "stack.h"

void	error_exit(void);
void	free_double(char **ptr);
void	free_triple(char ***list);
void	free_and_exit(t_stack *pa, t_stack *pb, char ***list);

#endif
