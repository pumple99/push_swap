/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 19:33:47 by seunghoy          #+#    #+#             */
/*   Updated: 2023/01/13 21:13:37 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/gnl.h"
#include "libft/pf_printf.h"
#include "libft/libft.h"
#include "push_swap.h"

static void	exe_or_exit(t_stack *a, t_stack *b, char temp[], int *e)
{
	if (!ft_strncmp(temp, "sa\n", 3))
		swap(a);
	else if (!ft_strncmp(temp, "sb\n", 3))
		swap(b);
	else if (!ft_strncmp(temp, "ss\n", 3))
		(swap(a) || swap(b));
	else if (!ft_strncmp(temp, "pa\n", 3))
		push(b, a, e);
	else if (!ft_strncmp(temp, "pb\n", 3))
		push(a, b, e);
	else if (!ft_strncmp(temp, "ra\n", 3))
		ro(a);
	else if (!ft_strncmp(temp, "rb\n", 3))
		ro(b);
	else if (!ft_strncmp(temp, "rr\n", 3))
		(ro(a) || ro(b));
	else if (!ft_strncmp(temp, "rra\n", 4))
		rro(a);
	else if (!ft_strncmp(temp, "rrb\n", 4))
		rro(b);
	else if (!ft_strncmp(temp, "rrr\n", 4))
		(rro(a) || rro(b));
	else
		*e = PS_ERR_WRONG_INPUT;
}

static void	print_result(int is_sorted, int *e)
{
	int	return_print;
	
	if (is_sorted)
		return_print = ft_printf("OK\n");
	else
		return_print = ft_printf("KO\n");
	if (return_print < 0)
		*e = PS_ERR_PF;
}

static int	exe_input_op(t_stack *a, t_stack *b, int *e)
{
	char	*in;

	in = get_next_line(0);
	if (in == (char *)1)
		*e = PS_ERR_GNL;
	while (in && *e == 0)
	{
		exe_or_exit(a, b, in, e);
		free(in);
		in = get_next_line(0);
		if (in == (char *)1)
			*e = PS_ERR_GNL;
	}
	if (*e == 0)
		print_result(is_complete(a, b), e);
	return (*e);
}

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
	(e || exe_input_op(a, b, &e));
	clean_all(a, b, arr);
	if (e)
		print_error_exit();
}
