#ifndef PUSHSWAP_H
# define PUSHSWAP_H

#include "../Libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct		s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct		s_deq
{
	t_node			*head; //처음 노드
	t_node			*tail; //마지막 노드
}					t_deq;

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

//deque.c
void			ft_init(t_deq *a, t_deq *b);
void			ft_create_deq(int *stack, t_deq *deq, int count);

//qsort.c
int				*ft_get_sortstack(int argc, char **argv, int count);
void			ft_quick_sort(int *stack, int start, int end);

//sort.c
void			divide_ra(t_deq *a, t_deq *b, t_pivot pv, int count);
void			divide_pb(t_deq *a, t_deq *b, t_pivot pv, int count);
void			divide_rb(t_deq *a, t_deq *b, t_pivot pv, int count);
void			divide_pbra(t_deq *a, t_deq *b, t_pivot pv, int count);

//last_sort_case.c
int				sort_case(t_deq *a, t_deq *b, int count);
int				sort_case3(t_deq *a, t_deq *b);

//sort_case4.c
int				sort_case4(t_deq *a, t_deq *b);

//sort_case5.c
int				sort_case5(t_deq *a, t_deq *b);

//ustils.c
void			ft_get_pivot(int *stack, t_pivot *pv, int count);
int				ft_get_5pivot(int *stack);
int				ft_count_arg(char **s, char c);
int				*put_stack(t_node *deq, int count);
int				*put_stack2(t_node *deq, int count);
void			show(int *stack, int count);
void			dsp_init(t_dsp *dsp);
void			print_deq(t_deq *a, t_deq *b, t_dsp dsp);
int				ft_check_ahead(t_deq *deq, int count);
int				ft_check_atail(t_deq *deq, int count);
int				ft_check_bhead(t_deq *deq, int count);
int				ft_check_btail(t_deq *deq, int count);

void			sa(t_deq *a);
void			sb(t_deq *b);
void			ss(t_deq *a, t_deq *b);
void			pa(t_deq *a, t_deq *b);
void			pb(t_deq *b, t_deq *a);
void			ra(t_deq *a);
void			rb(t_deq *b);
void			rr(t_deq *a, t_deq *b);
void			rra(t_deq *a);
void			rrb(t_deq *b);
void			rrr(t_deq *a, t_deq *b);

void			show(int *stack, int count);

#endif
