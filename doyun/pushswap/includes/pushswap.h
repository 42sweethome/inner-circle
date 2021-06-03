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
//ustils.c
void			ft_get_pivot(int *stack, t_pivot *pv, int count);
int				ft_count_arg(char **s, char c);

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
