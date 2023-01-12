/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trisection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:12:48 by seunghoy          #+#    #+#             */
/*   Updated: 2023/01/09 16:12:51 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/pf_printf.h"

static void	trisec_atop(t_stack *a, t_stack *b, t_block blo, int *e)
{
	int		idx;
	t_node	*at;

	idx = 0 - 1;
	while (++idx < blo.count)
	{
		at = a->top;
		if (blo.p2 < at->idx)
		{
			ro(a);
			ft_printf("ra\n");
		}
		else if (blo.p1 < at->idx && at->idx <= blo.p2)
		{
			push(a, b, e);
			ft_printf("pb\n");
		}
		else if (at->idx <= blo.p1)
		{
			(push(a, b, e) || ro(b));
			ft_printf("pb\nrb\n");
		}
	}
}

static void	trisec_abot(t_stack *a, t_stack *b, t_block blo, int *e)
{
	int		idx;
	t_node	*ab;

	idx = 0 - 1;
	while (++idx < blo.count)
	{
		ab = a->top->next;
		if (blo.p2 < ab->idx)
		{
			rro(a);
			ft_printf("rra\n");
		}
		else if (blo.p1 < ab->idx && ab->idx <= blo.p2)
		{
			(rro(a) || push(a, b, e));
			ft_printf("rra\npb\n");
		}
		else if (ab->idx <= blo.p1)
		{
			(rro(a) || push(a, b, e) || ro(b));
			ft_printf("rra\npb\nrb\n");
		}
	}
}

static void	trisec_btop(t_stack *a, t_stack *b, t_block blo, int *e)
{
	int		idx;
	t_node	*bt;

	idx = 0 - 1;
	while (++idx < blo.count)
	{
		bt = b->top;
		if (blo.p2 < bt->idx)
		{
			push(b, a, e);
			ft_printf("pa\n");
		}
		else if (blo.p1 < bt->idx && bt->idx <= blo.p2)
		{
			(push(b, a, e) || ro(a));
			ft_printf("pa\nra\n");
		}
		else if (bt->idx <= blo.p1)
		{
			ro(b);
			ft_printf("rb\n");
		}
	}
}

static void	trisec_bbot(t_stack *a, t_stack *b, t_block blo, int *e)
{
	int		idx;
	t_node	*bb;

	idx = 0 - 1;
	while (++idx < blo.count)
	{
		bb = b->top->next;
		if (blo.p2 < bb->idx)
		{
			(rro(b) || push(b, a, e));
			ft_printf("rrb\npa\n");
		}
		else if (blo.p1 < bb->idx && bb->idx <= blo.p2)
		{
			rro(b);
			ft_printf("rrb\n");
		}
		else if (bb->idx <= blo.p1)
		{
			(rro(b) || push(b, a, e) || ro(a));
			ft_printf("rrb\npa\nra\n");
		}
	}
}

void	trisec_print(t_stack *a, t_stack *b, t_block blo, int *e)
{
	if (blo.pos == a_top)
		trisec_atop(a, b, blo, e);
	else if (blo.pos == a_bot)
		trisec_abot(a, b, blo, e);
	else if (blo.pos == b_top)
		trisec_btop(a, b, blo, e);
	else if (blo.pos == b_bot)
		trisec_bbot(a, b, blo, e);
}
