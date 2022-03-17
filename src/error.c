/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:52:06 by wocho             #+#    #+#             */
/*   Updated: 2022/03/17 13:52:24 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "../include/free.h"
#include "../include/error.h"

void	error_exit(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	free_and_exit(t_stack *pa, t_stack *pb, char ***list)
{
	free_triple(list);
	free_stacks(pa, pb);
	error_exit();
}
