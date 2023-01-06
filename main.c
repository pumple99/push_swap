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
	int		idx;

	if (argc < 2)
		return (0);
	a = make_stack();
	b = make_stack();
	arr = (t_sort *)malloc(sizeof(t_sort) * (argc - 1));
	idx = -1;
	while (++idx + 1 < argc)
		arr[idx].num[0] = atoi_or_exit(argv[argc - idx - 1], a, b, arr);
	find_idx_check_dup(idx, a, b, arr);
	idx = -1;
	while (++idx + 1 < argc)
		insert_stack(a, arr[idx].num[0], arr[idx].num[2]);
	
	clean_all(a, b, arr);
}
