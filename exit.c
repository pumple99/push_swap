/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 20:09:32 by seunghoy          #+#    #+#             */
/*   Updated: 2023/01/06 20:14:52 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "push_swap.h"

void	clean_all(t_stack *a, t_stack *b, t_sort *arr)
{
	free(arr);
	delete_stack(a);
	delete_stack(b);
}

void	print_error_exit(t_stack *a, t_stack *b, t_sort *arr)
{
	clean_all(a, b, arr);
	write(2, "Error\n", 6);
	exit(1);
}
