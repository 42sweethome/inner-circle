/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 19:05:08 by junghan           #+#    #+#             */
/*   Updated: 2021/04/26 21:29:45 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>


typedef struct	s_circle
{
	struct s_circle *next;
	struct s_circle *pre; //have to do
	int	value;
}				t_circle;

typedef struct	s_info
{
	int		len_a;
	int		len_b;
}				t_info;

typedef struct	s_link
{
	t_circle	*head;
	t_circle	*tail;
	t_circle	*node;
}				t_link;

void		func_sa(t_link *st_a, t_info info);
void		func_sb(t_link *st_b, t_info info);
void		func_ss(t_link *st_a, t_link *st_b, t_info info);
void		func_ra(t_link *st_a);
void		func_rb(t_link *st_b);
void		func_rr(t_link *st_a, t_link *st_b);
void		func_rra(t_link *st_a);
void		func_rrb(t_link *st_b);
void		func_rrr(t_link *st_a, t_link *st_b);
void		func_pa(t_link *st_a, t_link *st_b, t_info *info);
void		func_pb(t_link *st_a, t_link *st_b, t_info *info);

void		lstadd_back(t_circle **head, t_circle **tail, t_circle *new);
t_circle	*lstnew(int content, int *len);
int		input_int(t_link *st_a, char *s, char c, int *len);
void	quick_sort(int *st_a, int *st_b, int start, int end);
#endif
