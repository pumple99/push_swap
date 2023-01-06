/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:56:11 by seunghoy          #+#    #+#             */
/*   Updated: 2022/12/23 19:30:51 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_stack *s)
{
	t_node	*last;
	t_node	*new_top;

	if (s->arg_num < 2)
		return (1);
	else if (s->arg_num == 2)
	{
		s->top = s->top->next;
		return (1);
	}
	new_top = s->top->prev;
	new_top->prev->next = s->top;
	last = s->top->next;
	last->prev = new_top;
	s->top->next = new_top;
	s->top->prev = new_top->prev;
	new_top->next = last;
	new_top->prev = s->top;
	s->top = new_top;
	return (1);
}

int	push(t_stack *src, t_stack *dest)
{
	t_sort	num;

	if (is_stack_empty(src))
		return (1);
	num = pop_stack(src);
	insert_stack(dest, num.num[0], num.num[2]);
	return (1);
}

int	rotate(t_stack *s)
{
	if (s->arg_num < 2)
		return (1);
	s->top = s->top->prev;
	return (1);
}

int	rrotate(t_stack *s)
{
	if (s->arg_num < 2)
		return (1);
	s->top = s->top->next;
	return (1);
}
