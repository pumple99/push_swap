/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 21:11:24 by seunghoy          #+#    #+#             */
/*   Updated: 2023/01/09 21:11:25 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/pf_printf.h"

static void	pile_btop3(t_stack *a, t_stack *b)
{
	t_node  *t;
    t_node  *p;

    t = b->top;
    p = b->top->prev;
	if (t->idx < p->idx && p->idx < p->prev->idx)
		(push(b, a) && swap(b) && push(b, a) && swap(a) && push(b, a) && \
		swap(a) && ft_printf("pa\nsb\npa\nsa\npa\nsa\n"));
	else if (t->idx < p->prev->idx && p->prev->idx < p->idx)
		(push(b, a) && ro(a) && push(b, a) && push(b, a) && \
		rro(a) && ft_printf("pa\nra\npa\npa\nrra\n"));
	else if (p->idx < t->idx && t->idx < p->prev->idx)
		(push(b, a) && push(b, a) && ro(a) && push(b, a) && swap(a) && \
		rro(a) && ft_printf("pa\npa\nra\npa\nsa\nrra\n"));
	else if (p->prev->idx < t->idx && t->idx < p->idx)
		(push(b, a) && push(b, a) && swap(a) && push(b, a) && \
		ft_printf("pa\npa\nsa\npa\n"));
	else if (p->idx < p->prev->idx && p->prev->idx < t->idx)
		(push(b, a) && push(b, a) && push(b, a) && swap(a) && \
		ft_printf("pa\npa\npa\nsa\n"));
	else if (p->prev->idx < p->idx && p->idx < t->idx)
		(push(b, a) && push(b, a) && push(b, a) && \
		ft_printf("pa\npa\npa\n"));
}

void	pile_btop(t_stack *a, t_stack *b, t_block blo)
{
    t_node  *t;
    t_node  *p;

    t = b->top;
    p = b->top->prev;
	if (blo.count == 1)
		(push(b, a) && ft_printf("pa\n"));
	else if (blo.count == 2)
	{
		if (p->idx < t->idx)
			(push(b, a) && push(b, a) && ft_printf("pa\npa\n"));
		else if (p->idx > t->idx)
			(push(b, a) && push(b, a) && swap(a) && \
			ft_printf("pa\npa\nsa\n"));
	}
	else if (blo.count == 3)
		pile_btop3(a, b);
}

static void	pile_bbot3(t_stack *a, t_stack *b)
{
	t_node  *bot;
    t_node  *n;

    bot = b->top->next;
    n = bot->next;
	if (n->next->idx < n->idx && n->idx < bot->idx)
		(rro(b) && push(b, a) && rro(b) && push(b, a) && rro(b) && \
		push(b, a) && ft_printf("rrb\npa\nrrb\npa\nrrb\npa\n"));
	else if (n->next->idx < bot->idx && bot->idx < n->idx)
		(rro(b) && rro(b) && push(b, a) && push(b, a) && rro(b) && \
		push(b, a) && ft_printf("rrb\nrrb\npa\npa\nrrb\npa\n"));
	else if (n->idx < n->next->idx && n->next->idx < bot->idx)
		(rro(b) && push(b, a) && rro(b) && rro(b) && push(b, a) && \
		push(b, a) && ft_printf("rrb\npa\nrrb\nrrb\npa\npa\n"));
	else if (bot->idx < n->next->idx && n->next->idx < n->idx)
		(rro(b) && rro(b) && push(b, a) && rro(b) && push(b, a) && push(b, a) \
		&& ft_printf("rrb\nrrb\npa\nrrb\npa\npa\n"));
	else if (n->idx < bot->idx && bot->idx < n->next->idx)
		(rro(b) && rro(b) && swap(b) && rro(b) && push(b, a) && push(b, a) && \
		push(b, a) && ft_printf("rrb\nrrb\nsb\nrrb\npa\npa\npa\n"));
	else if (bot->idx < n->idx && n->idx < n->next->idx)
		(rro(b) && rro(b) && rro(b) && push(b, a) && push(b, a) && push(b, a) \
		&& ft_printf("rrb\nrrb\nrrb\npa\npa\npa\n"));
}

void	pile_bbot(t_stack *a, t_stack *b, t_block blo)
{
    t_node  *bot;
    t_node  *n;

    bot = b->top->next;
    n = bot->next;
	if (blo.count == 1)
		(rro(b) && push(b, a) && ft_printf("rrb\npa\n"));
	else if (blo.count == 2)
	{
		if (n->idx > bot->idx)
			(rro(b) && rro(b) && push(b, a) && push(b, a) && \
            ft_printf("rrb\nrrb\npa\npa\n"));
		else if (n->idx < bot->idx)
			(rro(b) && push(b, a) && rro(b) && push(b, a) && \
			ft_printf("rrb\npa\nrrb\npa\n"));
	}
	else if (blo.count == 3)
		pile_bbot3(a, b);
}
