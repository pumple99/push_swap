/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:33:00 by seunghoy          #+#    #+#             */
/*   Updated: 2023/01/09 17:33:02 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/pf_printf.h"

void	pile_atop(t_stack *a, t_block blo)
{
	t_node	*t;
	t_node	*p;

	t = a->top;
	p = a->top->prev;
	if (blo.count == 2 && p->idx < a->top->idx)
		(swap(a) && ft_printf("sa\n"));
	else if (blo.count == 3)
	{
		if (t->idx < p->prev->idx && p->prev->idx < p->idx)
			(ro(a) && swap(a) && rro(a) && ft_printf("ra\nsa\nrra\n"));
		else if (p->idx < t->idx && t->idx < p->prev->idx)
			(swap(a) && ft_printf("sa\n"));
		else if (p->prev->idx < t->idx && t->idx < p->idx)
			(ro(a) && swap(a) && rro(a) && swap(a) && \
			ft_printf("ra\nsa\nrra\nsa\n"));
		else if (p->idx < p->prev->idx && p->prev->idx < t->idx)
			(swap(a) && ro(a) && swap(a) && rro(a) && \
			ft_printf("sa\nra\nsa\nrra\n"));
		else if (p->prev->idx < p->idx && p->idx < t->idx)
			(swap(a) && ro(a) && swap(a) && rro(a) && swap(a) && \
			ft_printf("sa\nra\nsa\nrra\nsa\n"));
	}
}

static void	pile_abot3(t_stack *a, t_stack *b)
{
	t_node	*bot;
	t_node	*n;

	bot = a->top->next;
	n = bot->next;
	if (n->next->idx < n->idx && n->idx < bot->idx)
		(rro(a) && rro(a) && rro(a) && \
		ft_printf("rra\nrra\nrra\n"));
	else if (n->next->idx < bot->idx && bot->idx < n->idx)
		(rro(a) && rro(a) && swap(a) && rro(a) && \
		ft_printf("rra\nrra\nsa\nrra\n"));
	else if (n->idx < n->next->idx && n->next->idx < bot->idx)
		(rro(a) && rro(a) && rro(a) && swap(a) && \
		ft_printf("rra\nrra\nrra\nsa\n"));
	else if (bot->idx < n->next->idx && n->next->idx < n->idx)
		(rro(a) && rro(a) && swap(a) && rro(a) && swap(a) && \
		ft_printf("rra\nrra\nsa\nrra\nsa\n"));
	else if (n->idx < bot->idx && bot->idx < n->next->idx)
		(rro(a) && rro(a) && push(a, b) && rro(a) && swap(a) && \
		push(b, a) && ft_printf("rra\nrra\npb\nrra\nsa\npa\n"));
	else if (bot->idx < n->idx && n->idx < n->next->idx)
		(rro(a) && push(a, b) && rro(a) && rro(a) && swap(a) && \
		push(b, a) && ft_printf("rra\npb\nrra\nrra\nsa\npa\n"));
}

void	pile_abot(t_stack *a, t_stack *b, t_block blo)
{
	t_node	*bot;
	t_node	*n;

	bot = a->top->next;
	n = bot->next;
	if (blo.count == 1)
		(rro(a) && ft_printf("rra\n"));
	else if (blo.count == 2)
	{
		if (n->idx < bot->idx)
			(rro(a) && rro(a) && ft_printf("rra\nrra\n"));
		else if (n->idx > bot->idx)
			(rro(a) && rro(a) && swap(a) && \
			ft_printf("rra\nrra\nsa\n"));
	}
	else if (blo.count == 3)
		pile_abot3(a, b);
}

int	pile_print(t_stack *a, t_stack *b, t_block blo)
{
	if (blo.pos == a_top)
		pile_atop(a, blo);
	else if (blo.pos == a_bot)
		pile_abot(a, b, blo);
	else if (blo.pos == b_top)
		pile_btop(a, b, blo);
	else if (blo.pos == b_bot)
		pile_bbot(a, b, blo);
	return (1);
}
