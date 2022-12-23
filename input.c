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

#include <unistd.h>
#include <stdlib.h>

static void	print_error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

static int	return_index(char c)
{
	if ('0' <= c && c <= '9')
		return ((int)(c - 48));
	return (-1);
}

static int	is_wrong_input(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
	{
		if (return_index(str[len++]) == -1)
			return (1);
	}
	if (len == 0 || len > 10)
		return (1);
	return (0);
}

static long long	make_int(const char *str, int is_minus)
{
	int			index;
	long long	num;

	index = 0;
	num = 0;
	while (return_index(str[index]) != -1)
	{
		num *= 10;
		num += return_index(str[index]);
		index++;
	}
	if (is_minus)
		return (-num);
	return (num);
}

int	atoi_or_exit(const char *str)
{
	int			is_minus;
	long long	num;	

	is_minus = 0;
	if (str[index] == '-')
		is_minus++;
	if (is_wrong_input(str + is_minus))
		print_error_exit();
	num = make_int(str + is_minus, is_minus);
	if (num > 2147483647 || num < -2147483648)
		print_error_exit();
	if (num == 0 && str[0] != '0' && str[1] != 0)
		print_error_exit();
	return ((int)num);
}
