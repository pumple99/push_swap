/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:25:15 by seunghoy          #+#    #+#             */
/*   Updated: 2022/12/21 21:46:00 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_input(char *input)
{
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	a = make_stack();
	b = make_stack();
	while (argc > 1)
		insert_stack(a, check_input(argv[--argc]));
	//not yet
}
