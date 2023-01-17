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
	if (!ft_strncmp(temp, "sa", 3))
		swap(a);
	else if (!ft_strncmp(temp, "sb", 3))
		swap(b);
	else if (!ft_strncmp(temp, "ss", 3))
		(swap(a) || swap(b));
	else if (!ft_strncmp(temp, "pa", 3))
		push(b, a, e);
	else if (!ft_strncmp(temp, "pb", 3))
		push(a, b, e);
	else if (!ft_strncmp(temp, "ra", 3))
		ro(a);
	else if (!ft_strncmp(temp, "rb", 3))
		ro(b);
	else if (!ft_strncmp(temp, "rr", 3))
		(ro(a) || ro(b));
	else if (!ft_strncmp(temp, "rra", 4))
		rro(a);
	else if (!ft_strncmp(temp, "rrb", 4))
		rro(b);
	else if (!ft_strncmp(temp, "rrr", 4))
		(rro(a) || rro(b));
	else
		*e = PS_ERR_WRONG_INPUT;
}

static void	delete_nl(char temp[], char *input)
{
	int	idx;

	idx = 0;
	while (input[idx] && idx < 4)
	{
		if (input[idx] != '\n')
			temp[idx] = input[idx];
		else
			break ;
		idx++;
	}
	temp[idx] = 0;
}

static int	exe_input_op(t_stack *a, t_stack *b, int *e)
{
	char	*in;
	char	temp[5];

	in = get_next_line(0);
	while (in && *e == 0)
	{
		delete_nl(temp, in);
		free(in);
		exe_or_exit(a, b, temp, e);
		in = get_next_line(0);
	}
	if (*e == 0)
	{
		if (is_complete(a, b))
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	return (*e);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	t_sort	*arr;
	int		e;
	int		total;

	e = 0;
	a = make_stack(&e);
	b = make_stack(&e);
	total = count_input(argc, argv);
	if (total < 1)
		return (0);
	arr = make_input_arr(total, &e);
	(e || assign_input_arr(argc, argv, arr, &e));
	(e || find_idx_check_dup(total, arr, &e));
	(e || stack_a_initialize(a, arr, total, &e));
	(e || exe_input_op(a, b, &e));
	clean_all(a, b, arr);
	if (e)
		print_error_exit();
}
