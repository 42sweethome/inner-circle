/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_pbra.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <doyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 18:52:26 by doyun             #+#    #+#             */
/*   Updated: 2021/06/14 15:56:51 by doyun            ###   ########.fr       */
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
//	printf("pbra fin\n");
}

void		divide_pbra(t_deq *a, t_deq *b, t_pivot pv, int count)
{
//	printf("\nstart pbra\n");
	t_dsp dsp;
	int i;
	int *stack;

	i = 0;
	dsp_init(&dsp);
	if (ft_check_atail(a, count))
	{
		while (count--)
			rra(a);
		return ;
	}
//	printf("pbra 범인 : %d %d %d\n", pv.p1, pv.p2, count);
	if(count <= 2)
	{
		return (last_sort_pbra(a, count));
	}
	while (i < count)
	{
		if (a->head->value >= pv.p2)
		{
			ra(a);
			dsp.ra++;
		}
		else if (a->head->value <= pv.p1)
		{
			//rra(a);
			pb(b, a);
		//	rb(b);
			dsp.pb++;
		}
		else
		{
			//rra(a);
			pb(b, a);
			rb(b);
			dsp.rb++;
		}
		i++;
	}
	while (dsp.ra--)
	{
		rra(a);
		dsp.rra++;
	}

	stack = put_stack(a->head, dsp.rra);
//	show(stack, dsp.rra);
	ft_get_pivot(stack, &pv, dsp.rra);
	divide_ra(a, b, pv, dsp.rra);

/*	stack = put_stack(b->head, dsp.pb);
//	show(stack, dsp.pb);
	ft_get_pivot(stack, &pv, dsp.pb);
	divide_pb(a, b, pv, dsp.pb);
*/
	stack = put_stack(b->head, dsp.rb);
//	show(stack, dsp.rb);
	ft_get_pivot(stack, &pv, dsp.rb);
	divide_rb(a, b, pv, dsp.rb);

	stack = put_stack(b->head, dsp.pb);
//	show(stack, dsp.pb);
	ft_get_pivot(stack, &pv, dsp.pb);
	divide_pb(a, b, pv, dsp.pb);
	//printf("pbra fin\n");
}
