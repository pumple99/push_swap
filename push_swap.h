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

# define PS_ERR_MALLOC 1
# define PS_ERR_WRONG_INPUT 2
# define PS_ERR_DUPLICATE_INPUT 3

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

//pile.c || pile2.c
int		pile_print(t_stack *a, t_stack *b, t_block blo, int *e);
void	pile_atop(t_stack *a, t_block blo);
void	pile_abot(t_stack *a, t_stack *b, t_block blo, int *e);
void	pile_btop(t_stack *a, t_stack *b, t_block blo, int *e);
void	pile_bbot(t_stack *a, t_stack *b, t_block blo, int *e);

//sort.c
int		start_sort(t_stack *a, t_stack *b, int total, int *e);

//trisection.c
void	trisec_print(t_stack *a, t_stack *b, t_block blo, int *e);

//exit.c
void	print_error_exit(void);
void	clean_all(t_stack *a, t_stack *b, t_sort *arr);

//input.c || input2.c
int		atoi_or_exit(const char *str, int *e);
int		find_idx_check_dup(int total, t_sort *arr, int *e);
int		count_input(int argc, char *argv[]);
t_sort	*make_input_arr(int total, int *e);
int		assign_input_arr(int argc, char *argv[], t_sort *arr, int *e);
int		stack_a_initialize(t_stack *a, t_sort *arr, int total, int *e);

//stack.c
t_stack	*make_stack(int *e);
int		is_stack_empty(t_stack *s);
int		insert_stack(t_stack *s, int num, int idx, int *e);
t_sort	pop_stack(t_stack *s);
void	delete_stack(t_stack *s);

//operation.c
int		swap(t_stack *s);
int		push(t_stack *src, t_stack *dest, int *e);
int		ro(t_stack *s);
int		rro(t_stack *s);

#endif
