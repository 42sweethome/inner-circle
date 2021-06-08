/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <doyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 18:52:26 by doyun             #+#    #+#             */
/*   Updated: 2021/06/04 20:39:15 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void		last_sort_pbra(t_deq *a, int count)
{
	t_node *temp;

	if (count == 0)
		return ;
	else if (count == 1)
		rra(a);
	else
	{
		while (count--)
			rra(a);
		temp = a->head->next;
		if (a->head->value > temp->value)
			sa(a);
	}
}

void		divide_pbra(t_deq *a, t_deq *b, t_pivot pv, int count)
{
	printf("\nstart pbra\n");
	t_dsp dsp;
	int i;
	int *stack;

	i = 0;
	dsp_init(&dsp);
	printf("pbra 범인 : %d %d %d\n", pv.p1, pv.p2, count);
	if(count <= 2)
	{
		return (last_sort_pbra(a, count));
	}
	while (i < count)
	{
		if (a->tail->value >= pv.p2)
		{
			rra(a);
			dsp.rra++;
		}
		else if (a->tail->value <= pv.p1)
		{
			rra(a);
			pb(b, a);
			rb(b);
			dsp.rb++;
		}
		else
		{
			rra(a);
			pb(b, a);
			dsp.pb++;
		}
		i++;
	}
	stack = put_stack(a->head, dsp.rra);
	show(stack, dsp.rra);
	ft_get_pivot(stack, &pv, dsp.rra);
	divide_rb(a, b, pv, dsp.rra);

	stack = put_stack(b->head, dsp.pb);
	show(stack, dsp.pb);
	ft_get_pivot(stack, &pv, dsp.pb);
	divide_pb(a, b, pv, dsp.pb);

	stack = put_stack2(b->tail, dsp.rb);
	show(stack, dsp.rb);
	ft_get_pivot(stack, &pv, dsp.rb);
	divide_rb(a, b, pv, dsp.rb);
}
