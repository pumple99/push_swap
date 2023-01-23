#include "push_swap.h"
#include "libft/pf_printf.h"

int	sa(t_stack *a, int *e)
{
	swap(a);
	if (ft_print("sa\n") < 0)
	{
		*e = PS_ERR_PF;
		return (1);
	}
	return (0);
}

int	sb(t_stack *b, int *e)
{
	swap(b);
	if (ft_print("sb\n") < 0)
	{
		*e = PS_ERR_PF;
		return (1);
	}
	return (0);
}

int	ra(t_stack *a, int *e)
{
	ro(a);
	if (ft_print("ra\n") < 0)
	{
		*e = PS_ERR_PF;
		return (1);
	}
	return (0);
}

int	rb(t_stack *b, int *e)
{
	ro(b);
	if (ft_print("rb\n") < 0)
	{
		*e = PS_ERR_PF;
		return (1);
	}
	return (0);
}

int	rr(t_stack *a, t_stack *b, int *e)
{
	(ro(a) || ro(b));
	if (ft_print("rr\n") < 0)
	{
		*e = PS_ERR_PF;
		return (1);
	}
	return (0);
}

