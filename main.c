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
	int		input;

	input = 0;
	a = make_stack();
	b = make_stack();
	while (argc > 1)
		insert_stack(a, atoi_or_exit(argv[--argc]));
	//not yet
	delete_stack(a);
	delete_stack(b);
}
