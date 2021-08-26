/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 12:37:53 by daekim            #+#    #+#             */
/*   Updated: 2021/05/23 12:37:55 by daekim           ###   ########.fr       */
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

typedef struct		s_circle
{
	struct s_circle	*next;
	struct s_circle	*pre;
	int				value;
}					t_circle;

typedef struct		s_info
{
	int				start;
	int				end;
	int				count;
	int				len_a;
	int				len_b;
	int				both;
	int				check;
	int				ra;
	int				rb;
	int				pa;
	int				pb;
}					t_info;

typedef struct		s_link
{
	t_circle		*head;
	t_circle		*tail;
	t_circle		*node;
}					t_link;

int					func_sa(t_link *st_a, t_info info);
int					func_sb(t_link *st_b, t_info info);
int					func_ss(t_link *st_a, t_link *st_b, t_info *info);
int					func_ra(t_link *st_a, t_info *info);
int					func_rb(t_link *st_b, t_info *info);
int					func_rr(t_link *st_a, t_link *st_b, t_info *info);
int					func_rra(t_link *st_a, t_info *info);
int					func_rrb(t_link *st_b, t_info *info);
int					func_rrr(t_link *st_a, t_link *st_b, t_info *info);
int					func_pa(t_link *st_a, t_link *st_b, t_info *info);
int					func_pb(t_link *st_a, t_link *st_b, t_info *info);
void				init_stack(t_link *stack_a, t_link *stack_b, t_info *info);
void				init_info(t_info *info);
void				check_err(int ret);
int					check_set(t_link *st_a, t_link *st_b);
int					check_sort(t_link *st_a, t_link *st_b, t_info *info);
int					check_order(t_link *st_a);
int					check_dup(t_link *st_a);
int					exit_a(t_link *st_a, int range, t_info *info);
int					exit_b(t_link *st_a, t_link *st_b, int range, t_info *info);
int					exit_easy(t_link *st_a, t_link *st_b, int range,
					t_info *info);
void				lstadd_back(t_circle **head, t_circle **tail,
					t_circle *new);
void				lstclear(t_circle **head, t_circle **tail);
t_circle			*lstnew(int content, int *len);
int					input_int(t_link *st_a, char *s, char c, int *len);
int					sort_st(t_link *stack_a, t_link *stack_b, t_info *info);
int					input_arr(t_link *st_a, int **num);
void				quick_sort(int *st_a, int start, int end);
void				first_pivot(int *num, int pivot[2], int size);
void				first_div(t_link *st_a, t_link *st_b, int pivot[2],
					t_info *info);
int					sort_a(t_link *st_a, t_link *st_b, int range);
int					sort_b(t_link *st_a, t_link *st_b, int range);
int					quick_a(t_link *st_a, t_link *st_b, t_info *info);
int					quick_b(t_link *st_a, t_link *st_b, t_info *info);
void				rerot_a(t_link *st_a, t_link *st_b, t_info info);
void				rerot_b(t_link *st_b, t_info info);
void				under_5(t_link *st_a, t_link *st_b, t_info *info, int *ret);
void				under_4(t_link *st_a, t_link *st_b, t_info *info, int *ret);
#endif
