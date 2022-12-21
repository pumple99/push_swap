/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 19:10:53 by seunghoy          #+#    #+#             */
/*   Updated: 2022/12/21 21:45:25 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>

typedef struct s_node
{
	int	num;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*last;
	int		arg_num;
}	t_stack;

//stack.c
t_stack	*make_stack(void);
int		is_stack_empty(t_stack *s);
void	insert_stack(t_stack *s, int num);
int		pop_stack(t_stack *s);
void	delete_stack(t_stack *s);

//atoi.c
int	s_atoi(const char *str);

#endif
