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

//arr[0] = num, arr[1] = input_idx, arr[2] = sort_idx
typedef struct s_sort
{
	int	num[3];
}	t_sort;

typedef struct s_node
{
	int				num;
	int				idx;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		arg_num;
}	t_stack;

typedef enum pos
{
	a_top = 0,
	a_bot,
	b_top,
	b_bot
}	t_pos;

typedef struct s_block
{
	int		start;
	int		end;
	int		count;
	int		p1;
	int		p2;
	t_pos	pos;
}	t_block;

//pile.c
int		pile_print(t_stack *a, t_stack *b, t_block blo);
void	pile_atop(t_stack *a, t_block blo);
void	pile_abot(t_stack *a, t_stack *b, t_block blo);

//pile2.c
void	pile_btop(t_stack *a, t_stack *b, t_block blo);
void	pile_bbot(t_stack *a, t_stack *b, t_block blo);

//sort.c
int		sort_ps(t_stack *a, t_stack *b, t_block blo);

//trisection.c
void	trisec_print(t_stack *a, t_stack *b, t_block blo);

//exit.c
void	print_error_exit(t_stack *a, t_stack *b, t_sort *arr);
void	clean_all(t_stack *a, t_stack *b, t_sort *arr);

//input.c
int		atoi_or_exit(const char *str, t_stack *a, t_stack *b, t_sort *arr);
void	find_idx_check_dup(int total, t_stack *a, t_stack *b, t_sort *arr);

//stack.c
t_stack	*make_stack(void);
int		is_stack_empty(t_stack *s);
void	insert_stack(t_stack *s, int num, int idx);
t_sort	pop_stack(t_stack *s);
void	delete_stack(t_stack *s);

//operation.c
int		swap(t_stack *s);
int		push(t_stack *src, t_stack *dest);
int		ro(t_stack *s);
int		rro(t_stack *s);

#endif
