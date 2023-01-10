/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:12:36 by seunghoy          #+#    #+#             */
/*   Updated: 2023/01/09 16:12:38 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	blo_info_big(t_block blo, t_block *new_blo)
{
	new_blo->end = blo.end;
	new_blo->start = blo.p2 + 1;
	if (blo.pos == a_top)
		new_blo->pos = a_bot;
	else
		new_blo->pos = a_top;
	return (1);
}

static int	blo_info_mid(t_block blo, t_block *new_blo)
{
	new_blo->end = blo.p2;
	new_blo->start = blo.p1 + 1;
	if (blo.pos == b_top)
		new_blo->pos = a_bot;
	else
		new_blo->pos = b_top;
	return (1);
}

static int	blo_info_small(t_block blo, t_block *new_blo)
{
	new_blo->end = blo.p1;
	new_blo->start = blo.start;
	if (blo.pos == b_bot)
		new_blo->pos = a_bot;
	else
		new_blo->pos = b_bot;
	return (1);
}

int	sort_ps(t_stack *a, t_stack *b, t_block blo)
{
	t_block	temp;

	blo.count = blo.end - blo.start + 1;
	blo.p1 = blo.start + (int)((float)blo.count / 3) - 1;
	blo.p2 = blo.start + (int)((float)blo.count / 3 * 2) - 1;
	if (blo.pos == a_bot && a->arg_num == blo.count)
		blo.pos = a_top;
	if (blo.pos == b_bot && b->arg_num == blo.count)
		blo.pos = b_top;
	if (blo.count < 4)
		return (pile_print(a, b, blo));
	trisec_print(a, b, blo);
	(blo_info_big(blo, &temp) && sort_ps(a, b, temp));
	(blo_info_mid(blo, &temp) && sort_ps(a, b, temp));
	(blo_info_small(blo, &temp) && sort_ps(a, b, temp));
	return (1);
}
