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

static void trisec_atop(t_stack *a, t_stack *b, t_block blo)
{
    int idx;

    idx = 0 - 1;
    while (++idx < blo.count)
    {
        if (blo.p2 < a->top->idx)
        {
            ro(a);
            ft_printf("ra\n");
        }
        else if (blo.p1 < a->top->idx && a->top->idx <= blo.p2)
        {
            push(a, b);
            ft_printf("pb\n");
        }
        else if (a->top->idx <= blo.p1)
        {
            (push(a, b) && ro(b));
            ft_printf("pb\nrb\n");
        }
    }
}

static void trisec_abot(t_stack *a, t_stack *b, t_block blo)
{
    int idx;

    idx = 0 - 1;
    while (++idx < blo.count)
    {
        if (blo.p2 < a->top->idx)
        {
            rro(a);
            ft_printf("rra\n");
        }
        else if (blo.p1 < a->top->idx && a->top->idx <= blo.p2)
        {
            (rro(a) && push(a, b));
            ft_printf("rra\npb\n");
        }
        else if (a->top->idx <= blo.p1)
        {
            (rro(a) && push(a, b) && ro(b));
            ft_printf("rra\npb\nrb\n");
        }
    }
}

static void trisec_btop(t_stack *a, t_stack *b, t_block blo)
{
    int idx;

    idx = 0 - 1;
    while (++idx < blo.count)
    {
        if (blo.p2 < a->top->idx)
        {
            push(b, a);
            ft_printf("pa\n");
        }
        else if (blo.p1 < a->top->idx && a->top->idx <= blo.p2)
        {
            (push(b, a) && ro(a));
            ft_printf("pa\nra\n");
        }
        else if (a->top->idx <= blo.p1)
        {
            ro(b);
            ft_printf("rb\n");
        }
    }
}

static void trisec_bbot(t_stack *a, t_stack *b, t_block blo)
{
    int idx;

    idx = 0 - 1;
    while (++idx < blo.count)
    {
        if (blo.p2 < a->top->idx)
        {
            (rro(b) && push(b, a));
            ft_printf("rrb\npa\n");
        }
        else if (blo.p1 < a->top->idx && a->top->idx <= blo.p2)
        {
            rro(b);
            ft_printf("rrb\n");
        }
        else if (a->top->idx <= blo.p1)
        {
            (rro(b) && push(b, a) && ro(a));
            ft_printf("rrb\npa\nra\n");
        }
    }
}

void    trisec_print(t_stack *a, t_stack *b, t_block blo)
{
    if (blo.pos == a_top)
        trisec_atop(a, b, blo);
    else if (blo.pos == a_bot)
        trisec_abot(a, b, blo);
    else if (blo.pos == b_top)
        trisec_btop(a, b, blo);
    else if (blo.pos == b_bot)
        trisec_bbot(a, b, blo);
}
