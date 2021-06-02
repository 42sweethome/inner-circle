/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <doyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:37:19 by doyun             #+#    #+#             */
/*   Updated: 2021/06/02 21:56:28 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int			*put_stack(t_node *deq, int count)
{
	int		*stack;
	int		idx;

	idx = -1;
	stack = (int *)ft_calloc(sizeof(int), count);
	while (deq != NULL)
	{
		stack[++idx] = deq->value;
		deq = deq->next;
	}
	return (stack);
}

void		divide_a(t_deq *a, t_deq *b, t_pivot pv, int count)
{
	t_dsp dsp;
	int i;

	i = 0;
	while(i < count)
	{
		if (a->head->value >= pv.p2)
		{
			ra(a);
			dsp.ra++;
		}
		else if (a->head->value <= pv.p1)
		{
			pb(b, a);
			dsp.pb++;
		}
		else
		{
			pb(b, a);
			rb(b);
			dsp.rb++;
		}
		i++;	
		printf("divide a : ");
		t_node *temp = a->head;
		while (temp != NULL)
		{
			printf("%d ",temp->value);
			temp = temp->next;
		}
		temp = b->head;
		printf("divide b : ");
		while (temp != NULL)
		{
			printf("%d ",temp->value);
			temp = temp->next;
		}
		printf("\n");
		printf("disposal : %d %d %d\n",dsp.ra, dsp.pb, dsp.rb);
	}
//	ft_quick_sort(put_stack(a->head, dsp.ra), 0, dsp.ra - 1);
}
