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

#include <unistd.h>
#include "push_swap.h"

static void	get_op(t_stack *a, t_stack *b)
{
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	a = make_stack();
	b = make_stack();
	while (argc > 1)
		insert_stack(a, atoi_or_exit(argv[--argc]));
	get_op(a, b);
	delete_stack(a);
	delete_stack(b);
}
