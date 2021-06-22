/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <doyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 11:24:23 by doyun             #+#    #+#             */
/*   Updated: 2021/06/22 12:50:45 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "../Libft/libft.h"
# include "./get_next_line.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct		s_deq
{
	t_node			*head;
	t_node			*tail;
}					t_deq;

typedef struct		s_buf
{
	t_deq			*a;
	t_deq			*b;
}					t_buf;

typedef struct		s_pivot
{
	int				p1;
	int				p2;
}					t_pivot;

typedef struct		s_dsp
{
	int				ra;
	int				rb;
	int				pb;
	int				pa;
	int				rrb;
	int				rra;
}					t_dsp;

int					get_next_line(int fd, char **line);
char				*str_dup(char *s1);
char				*sub_str(char *s, int start, size_t len);
char				*str_join(char *s1, char *s2);
int					str_len(char *s);

void				ft_init(t_buf *buf);
void				ft_create_deq(int *stack, t_deq *deq, int count);
void				ft_deqclear(t_node *node);

int					*ft_get_sortstack(int argc, char **argv, int count);
void				ft_quick_sort(int *stack, int start, int end);

void				divide_ra(t_buf *buf, t_pivot pv, int count, t_dsp pdsp);
void				divide_pb(t_buf *buf, t_pivot pv, int count);
void				divide_rrr(t_deq *a, t_deq *b, t_dsp dsp);

int					rs_case3(t_deq *a, t_deq *b);

int					sort_case(t_deq *a, t_deq *b, int count);
int					sort_case3(t_deq *a, t_deq *b);

int					sort_case3(t_deq *a, t_deq *b);
int					sort_case4(t_deq *a, t_deq *b, int idx);
int					sort_case5(t_deq *a, t_deq *b);
int					sort_case6(t_deq *a, t_deq *b);

int					*ft_check_dup(int *stack, int count);
void				ft_get_pivot(int *stack, t_pivot *pv, int count);
int					ft_get_npivot(int *stack, int count);
int					ft_count_arg(char **s, char c);
int					*put_stack(t_node *deq, int count);
int					*put_stack2(t_node *deq, int count);
void				show(int *stack, int count);
void				dsp_init(t_dsp *dsp);
void				print_deq(t_deq *a, t_deq *b, t_dsp dsp);
int					ft_check_ahead(t_deq *deq, int count);
int					ft_check_atail(t_deq *deq, int count);
int					ft_check_bhead(t_deq *deq, int count);
int					ft_check_btail(t_deq *deq, int count);
void				checker_free(t_buf *buf);

void				sa(t_deq *a);
void				sb(t_deq *b);
void				ss(t_deq *a, t_deq *b);
void				pa(t_deq *a, t_deq *b);
void				pb(t_deq *b, t_deq *a);
void				ra(t_deq *a);
void				rb(t_deq *b);
void				rr(t_deq *a, t_deq *b);
void				rra(t_deq *a);
void				rrb(t_deq *b);
void				rrr(t_deq *a, t_deq *b);

void				csa(t_deq *a);
void				csb(t_deq *b);
void				css(t_deq *a, t_deq *b);
void				cpa(t_deq *a, t_deq *b);
void				cpb(t_deq *b, t_deq *a);
void				cra(t_deq *a);
void				crb(t_deq *b);
void				crr(t_deq *a, t_deq *b);
void				crra(t_deq *a);
void				crrb(t_deq *b);
void				crrr(t_deq *a, t_deq *b);

#endif
