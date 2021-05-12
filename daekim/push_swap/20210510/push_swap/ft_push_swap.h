/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 19:05:08 by junghan           #+#    #+#             */
/*   Updated: 2021/05/10 17:38:56 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "./libft/libft.h"
# include "get_next_line.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# define SMALL	0
# define LARGE	1
# define LAST	2
/* small = 1/3 위치, large = 2/3 위치*/

typedef struct	s_circle
{
	struct s_circle *next;
	struct s_circle *pre; //have to do
	int	value;
}				t_circle;

typedef struct	s_info
{
	int		start;
	int		end;
	int		count;
	int		len_a;
	int		len_b;
	int		both;
	int		check;
	int		ra;
	int		rb;
	int		pa;
	int		pb;
}				t_info;

typedef struct	s_link
{
	t_circle	*head;
	t_circle	*tail;
	t_circle	*node;
}				t_link;

void		func_sa(t_link *st_a, t_info info);
void		func_sb(t_link *st_b, t_info info);
void		func_ss(t_link *st_a, t_link *st_b, t_info *info);
void		func_ra(t_link *st_a, t_info *info);
void		func_rb(t_link *st_b, t_info *info);
void		func_rr(t_link *st_a, t_link *st_b, t_info *info);
void		func_rra(t_link *st_a, t_info *info);
void		func_rrb(t_link *st_b, t_info *info);
void		func_rrr(t_link *st_a, t_link *st_b, t_info *info);
void		func_pa(t_link *st_a, t_link *st_b, t_info *info);
void		func_pb(t_link *st_a, t_link *st_b, t_info *info);


void		init_stack(t_link *stack_a, t_link *stack_b, t_info *info);
void		init_info(t_info *info);
int			check_sort(t_link *st_a, t_info *info);
int			check_order(t_link *st_a);
int			exit_a(t_link *st_a, int range, t_info *info);
int			exit_b(t_link *st_a, t_link *st_b, int range, t_info *info);
void		lstadd_back(t_circle **head, t_circle **tail, t_circle *new);
t_circle	*lstnew(int content, int *len);
int			input_int(t_link *st_a, char *s, char c, int *len);
int			sort_st(t_link *stack_a, t_link *stack_b, t_info *info);
int			input_arr(t_link *st_a, int **num);
void		quick_sort(int *st_a, int start, int end);
void		first_pivot(int *num, int pivot[3], int size);
void		first_div(t_link *st_a, t_link *st_b, int pivot[3], t_info *info);
int			sort_a(t_link *st_a, t_link *st_b, int range);
int			sort_b(t_link *st_a, t_link *st_b, int range);
int			quick_a(t_link *st_a, t_link *st_b, t_info *info);
int			quick_b(t_link *st_a, t_link *st_b, t_info *info);
void		rerot_a(t_link *st_a, t_info info);
void		rerot_b(t_link *st_b, t_info info);
#endif
