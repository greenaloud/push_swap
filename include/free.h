/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:55:59 by wocho             #+#    #+#             */
/*   Updated: 2022/03/17 14:56:01 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_H
# define FREE_H

# include "stack.h"

void	free_double(char **ptr);
void	free_triple(char ***list);
void	free_stacks(t_stack *pa, t_stack *pb);

#endif
