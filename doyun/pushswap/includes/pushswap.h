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

void			ft_deq_init(t_deq *a, t_deq *b);
void			ft_create_deq(int value, t_deq *deq);
int				*ft_get_pivot(char **argv, int count);
int				ft_count_arg(char **s, char c);
void			ft_quick_sort(int *stack, int start, int end);

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


#endif
