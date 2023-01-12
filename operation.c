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
		return (0);
	else if (s->arg_num == 2)
	{
		s->top = s->top->next;
		return (0);
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
	return (0);
}

int	push(t_stack *src, t_stack *dest, int *e)
{
	t_sort	num;

	if (is_stack_empty(src))
		return (0);
	num = pop_stack(src);
	return (insert_stack(dest, num.num[0], num.num[2], e));
}

int	ro(t_stack *s)
{
	if (s->arg_num < 2)
		return (0);
	s->top = s->top->prev;
	return (0);
}

int	rro(t_stack *s)
{
	if (s->arg_num < 2)
		return (0);
	s->top = s->top->next;
	return (0);
}
