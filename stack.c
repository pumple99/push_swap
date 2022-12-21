/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 19:17:35 by seunghoy          #+#    #+#             */
/*   Updated: 2022/12/21 20:44:43 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*make_stack(void)
{
	t_stack	*s;

	s = (t_stack *)malloc(sizeof(t_stack));
	s->top = 0;
	s->last = 0;
	s->arg_num = 0;
}

int	is_stack_empty(t_stack *s)
{
	if (s->arg_num == 0)
		return (1);
	return (0);
}

void	insert_stack(t_stack *s, int num)
{
	t_node	*n;

	n = (t_node *)malloc(sizeof(t_node));
	n->num = num;
	if (is_stack_empty(s))
	{
		n->prev = n;
		n->next = n;
	}
	s->top->next = n;
	s->last->prev = n;
	n->prev = s->top;
	n->next = s->last;
	s->top = n;
	(s->arg_num)++;
}

int	pop_stack(t_stack *s)
{
	t_node	*n;
	int		num;

	if (is_stack_empty(s))
		return (0);
	n = s->top;
	s->top = n->prev;
	s->top->next = s->last;
	s->last->prev = s->top;
	(s->arg_num)--;
	num = n->num;
	free(n);
	return (num);
}

void	delete_stack(t_stack *s)
{
	while (s->arg_num > 0)
		pop_stack(s);
	free(s);
}
