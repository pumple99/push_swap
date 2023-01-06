/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 19:33:47 by seunghoy          #+#    #+#             */
/*   Updated: 2022/12/23 21:35:31 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/get_next_line_bonus.h"
#include "libft/pf_printf.h"
#include "libft/libft.h"
#include "push_swap.h"

static int	is_complete(t_stack *a, t_stack *b)
{
	int		idx;
	t_node	*temp;

	if (!is_stack_empty(b))
		return (0);
	idx = 0;
	temp = a->top;
	while (++idx < a->arg_num)
	{
		if (temp->num > temp->prev->num)
			return (0);
		temp = temp->prev;
	}
	return (1);
}

static void	exe_or_exit(t_stack *a, t_stack *b, char temp[])
{
	if (!ft_strncmp(temp, "sa", 3))
		swap(a);
	else if (!ft_strncmp(temp, "sb", 3))
		swap(b);
	else if (!ft_strncmp(temp, "ss", 3))
		swap(a) && swap(b);
	else if (!ft_strncmp(temp, "pa", 3))
		push(b, a);
	else if (!ft_strncmp(temp, "pb", 3))
		push(a, b);
	else if (!ft_strncmp(temp, "ra", 3))
		rotate(a);
	else if (!ft_strncmp(temp, "rb", 3))
		rotate(b);
	else if (!ft_strncmp(temp, "rr", 3))
		rotate(a) && rotate(b);
	else if (!ft_strncmp(temp, "rra", 4))
		rrotate(a);
	else if (!ft_strncmp(temp, "rrb", 4))
		rrotate(b);
	else if (!ft_strncmp(temp, "rrr", 4))
		rrotate(a) && rrotate(b);
	else
		print_error_exit();
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
			break;
		idx++;
	}
	temp[idx] = 0;
}

static void	exe_input_op(t_stack *a, t_stack *b)
{
	char	*in;
	char	temp[5];

	in = get_next_line(0);
	while (in)
	{
		delete_nl(temp, in);
		free(in);
		exe_or_exit(a, b, temp);
		in = get_next_line(0);
	}
	if (is_complete(a, b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	int		*arr;
	int		num;
	int		idx;

	if (argc < 2)
		return (0);
	a = make_stack();
	b = make_stack();
	arr = (int *)malloc(sizeof(int) * (argc - 1));
	idx = 0;
	while (argc > 1)
	{
		num = atoi_or_exit(argv[--argc]);
		insert_stack(a, num);
		arr[idx++] = num;
	}
	exit_if_dup(arr, idx);
	exe_input_op(a, b);
	delete_stack(a);
	delete_stack(b);
}