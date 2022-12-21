/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 20:56:22 by seunghoy          #+#    #+#             */
/*   Updated: 2022/12/21 21:45:08 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	return_index(char c)
{
	if ('0' <= c && c <= '9')
		return ((int)(c - 48));
	return (-1);
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

int	s_atoi(const char *str)
{
	int	index;
	int	minus;

	index = 0;
	minus = 0;
	if (str[index] == '-')
	{
		minus++;
		index++;
	}
	return (make_int(str + index, minus));
}
