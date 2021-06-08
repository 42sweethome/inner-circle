/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_pb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <doyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 15:03:57 by doyun             #+#    #+#             */
/*   Updated: 2021/06/04 20:34:55 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void		last_sort_pb(t_deq *a, t_deq *b, int count)
{
	t_node *temp;

	temp = b->head->next;
	if (count == 0)
		return ;
	else if (count == 1)
		pa(a, b);
	else
	{
		if (b->head->value < temp->value)
			sb(b);
		while (count--)
			pa(a, b);
	}
}

void	divide_pb(t_deq *a, t_deq *b, t_pivot pv, int count)
{
	printf("\nstart pb\n");
	t_dsp dsp;
	int i;
	int	*stack;

	i = 0;
	dsp_init(&dsp);
	printf("pb 범인 : %d %d %d\n",pv.p1, pv.p2, count);
	if (count <= 2)
	{
		last_sort_pb(a, b, count);
		print_deq(a, b, dsp);
		printf("pb out\n");
		return ;

	}
	while(i < count)
	{
		if (b->head->value >= pv.p2)
		{
			pa(a, b);
			dsp.pa++;
		}
		else if (b->head->value <= pv.p1)
		{
			pa(a, b);
			ra(a);
			dsp.ra++;
		}
		else
		{
			rb(b);
			dsp.rb++;
		}
		i++;
		printf("pivot : %d %d\n",pv.p1, pv.p2);
		print_deq(a, b, dsp);
	}
	stack = put_stack(a->head, dsp.pa);
	show(stack, dsp.pa);
	ft_get_pivot(stack, &pv, dsp.pa);
	divide_ra(a, b, pv, dsp.pa);

	stack = put_stack2(a->tail, dsp.ra);
	show(stack, dsp.ra);
	ft_get_pivot(stack, &pv, dsp.ra);
	divide_pbra(a, b, pv, dsp.ra);

	stack = put_stack2(a->tail, dsp.ra);
	show(stack, dsp.ra);
	ft_get_pivot(stack, &pv, dsp.ra);	
	divide_pb(a, b, pv, dsp.ra);

	stack = put_stack(b->head, dsp.pb);
	show(stack, dsp.pb);
	ft_get_pivot(stack, &pv, dsp.pb);
	divide_rb(a, b, pv, dsp.pb);
}
