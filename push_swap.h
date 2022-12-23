/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 19:10:53 by seunghoy          #+#    #+#             */
/*   Updated: 2022/12/23 19:30:34 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_node
{
	int				num;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		arg_num;
}	t_stack;

//input.c
int		atoi_or_exit(const char *str);

//stack.c
t_stack	*make_stack(void);
int		is_stack_empty(t_stack *s);
void	insert_stack(t_stack *s, int num);
int		pop_stack(t_stack *s);
void	delete_stack(t_stack *s);

//operation.c
void	swap(t_stack *s);
void	push(t_stack *src, t_stack *dest);
void	rotate(t_stack *s);
void	rrotate(t_stack *s);

#endif
