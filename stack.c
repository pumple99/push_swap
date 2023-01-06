/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 19:17:35 by seunghoy          #+#    #+#             */
/*   Updated: 2022/12/23 18:52:47 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

t_stack	*make_stack(void)
{
	t_stack	*s;

	s = (t_stack *)malloc(sizeof(t_stack));
	s->top = 0;
	s->arg_num = 0;
	return (s);
}

int	is_stack_empty(t_stack *s)
{
	if (s->arg_num == 0)
		return (1);
	return (0);
}

void	insert_stack(t_stack *s, int num, int idx)
{
	t_node	*n;

	n = (t_node *)malloc(sizeof(t_node));
	n->num = num;
	n->idx = idx;
	if (is_stack_empty(s))
	{
		n->prev = n;
		n->next = n;
	}
	else
	{
		n->next = s->top->next;
		s->top->next = n;
		n->prev = s->top;
		n->next->prev = n;
	}
	s->top = n;
	(s->arg_num)++;
}

t_sort	pop_stack(t_stack *s)
{
	t_node	*n;
	t_sort	num;

	n = s->top;
	s->top = n->prev;
	s->top->next = n->next;
	n->next->prev = s->top;
	(s->arg_num)--;
	num.num[0] = n->num;
	num.num[2] = n->idx;
	free(n);
	if (s->arg_num == 0)
		s->top = 0;
	return (num);
}

void	delete_stack(t_stack *s)
{
	while (s->arg_num > 0)
		pop_stack(s);
	free(s);
}
