/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:23:45 by seunghoy          #+#    #+#             */
/*   Updated: 2023/01/12 17:23:47 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

int	count_input(int argc, char *argv[])
{
	int		is_in_word;
	int		count;
	int		idx;
	char	*str;

	count = 0;
	idx = 0;
	while (++idx < argc)
	{
		is_in_word = 0;
		str = argv[idx];
		while (*str)
		{
			if (!is_in_word && *str != ' ')
			{
				is_in_word = 1;
				count++;
			}
			else if (is_in_word && *str == ' ')
				is_in_word = 0;
			str++;
		}
	}
	return (count);
}

t_sort	*make_input_arr(int total, int *e)
{
	t_sort	*arr;

	arr = (t_sort *)malloc(sizeof(t_sort) * total);
	if (arr == 0)
		*e = PS_ERR_MALLOC;
	return (arr);
}

int	assign_input_arr(int argc, char *argv[], t_sort *arr, int *e)
{
	int		is_in_word;
	int		count;
	int		idx;
	char	*str;

	count = 0;
	idx = 0;
	while (++idx < argc && *e == 0)
	{
		is_in_word = 0;
		str = argv[idx];
		while (*str)
		{
			if (!is_in_word && *str != ' ')
			{
				is_in_word = 1;
				arr[count++].num[0] = atoi_or_exit(str, e);
			}
			else if (is_in_word && *str == ' ')
				is_in_word = 0;
			str++;
		}
	}
	return (0);
}

int	stack_a_initialize(t_stack *a, t_sort *arr, int total, int *e)
{
	int	idx;

	idx = -1;
	while (++idx < total && *e == 0)
		insert_stack(a, arr[idx].num[0], arr[idx].num[2], e);
	return (0);
}
