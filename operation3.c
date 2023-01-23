#include "push_swap.h"
#include "libft/pf_printf.h"

int	pa(t_stack *b, t_stack *a, int *e)
{
	if (push(b, a, e))
		return (1);
	if (ft_print("pa\n") < 0)
	{
		*e = PS_ERR_PF;
		return (1);
	}
	return (0);
}

int	pb(t_stack *a, t_stack *b, int *e)
{
	if (push(a, b, e))
		return (1);
	if (ft_print("pb\n") < 0)
	{
		*e = PS_ERR_PF;
		return (1);
	}
	return (0);
}

int	rra(t_stack *a, int *e)
{
	rro(a);
	if (ft_print("rra\n") < 0)
	{
		*e = PS_ERR_PF;
		return (1);
	}
	return (0);
}

int	rrb(t_stack *b, int *e)
{
	rro(b);
	if (ft_print("rrb\n") < 0)
	{
		*e = PS_ERR_PF;
		return (1);
	}
	return (0);
}

int	rrr(t_stack *a, t_stack *b, int *e)
{
	(rro(a) || rro(b));
	if (ft_print("rrr\n") < 0)
	{
		*e = PS_ERR_PF;
		return (1);
	}
	return (0);
}

