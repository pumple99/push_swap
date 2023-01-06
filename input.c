/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:21:47 by seunghoy          #+#    #+#             */
/*   Updated: 2022/12/23 17:21:26 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft/libft.h"
#include "push_swap.h"

static void	arr_swap(int *arr, int a, int b)
{
	int	temp;

	temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

static void	quick(int *arr, int l, int r)
{
	int left;
	int	right;
	int	pivot;

	left = l;
	right = r;
	pivot = arr[(l + r) / 2];
	while (left <= right)
	{
        while (arr[left] < pivot)
		    left++;
        while (arr[right] > pivot)
            right--;
        if (left <= right)
        {
            arr_swap(arr, left, right);
            left++;
            right--;
        }
	}
	if (l < right)
		quick(arr, l, right);
	if (left < r)
		quick(arr, left, r);
}

void	exit_if_dup(int *arr, int num)
{
	int	idx;

	idx = 0;
	quick(arr, 0, num - 1);
	while (idx < num - 1)
	{
		if (arr[idx] == arr[idx + 1])
			print_error_exit();
		idx++;
	}
}

static int	is_wrong_input(const char *str)
{
	int		len;

	len = 0;
	while (str[len])
	{
		if (str[len] < '0' || '9' < str[len])
			return (1);
		len++;
	}
	if (len == 0 || len > 10)
		return (1);
	return (0);
}

int	atoi_or_exit(const char *str)
{
	int			index;
	long long	num;	

	index = 0;
	if (str[0] == '-' || str[0] == '+')
		index++;
	if (is_wrong_input(str + index))
		print_error_exit();
	num = ft_atoi(str);
	if (num > INT_MAX || num < INT_MIN)
		print_error_exit();
	if (num == 0 && (str[0] != '0' || str[1] != 0))
		print_error_exit();
	return ((int)num);
}
