/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:25:15 by seunghoy          #+#    #+#             */
/*   Updated: 2022/12/23 17:48:02 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	t_sort	*arr;
	int		e;
	int		total;

	if (argc < 2)
		return (0);
	e = 0;
	total = 0;
	arr = 0;
	a = make_stack(&e);
	b = make_stack(&e);
	(e || count_input(argc, argv, &total, &e));
	(e || make_input_arr(total, &arr, &e));
	(e || assign_input_arr(argc, argv, arr, &e));
	(e || find_idx_check_dup(total, arr, &e));
	(e || stack_a_initialize(a, arr, total, &e));
	(e || start_sort(a, b, total, &e));
	clean_all(a, b, arr);
	if (e)
		print_error_exit();
}
