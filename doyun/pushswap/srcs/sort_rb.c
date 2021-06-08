/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <doyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 15:04:56 by doyun             #+#    #+#             */
/*   Updated: 2021/06/08 18:26:22 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void		last_sort_rb(t_deq *a, t_deq *b, int count)
{
	t_node *temp;

	temp = NULL;
	if (count == 0)
		return ;
	else if (count == 1)
	{
		rrb(b);
		pa(a, b);
	}
	else
	{
		while (count--)
		{
			rrb(b);
			pa(a, b);
		}
		if (a->head != NULL)
			temp = a->head->next;
		if (a->head->value > temp->value)
			sa(a);
	}
	t_dsp dsp;
	dsp_init(&dsp);
	print_deq(a, b, dsp);
	printf("rb out\n");
	return ;
}

void	divide_rb(t_deq *a, t_deq *b, t_pivot pv, int count)
{
	printf("\nstart rb\n");
	t_dsp dsp;
	int i;
	int *stack;

	i = 0;
	dsp_init(&dsp);	
/*	t_node *tmp;

	tmp = a->head;
	while (i++ < count && (tmp != NULL && tmp->next != NULL))
	{
		if (tmp->value < tmp->next->value)
			break;
		tmp = tmp->next;
		if (tmp == NULL || i == count)
			return ;
	}
	i = 0;*/
	printf("rb 범인 %d %d count : %d\n", pv.p1, pv.p2, count);
	if (count <= 2)
	{
		return(last_sort_rb(a, b, count));
	}
	while(i < count)
	{
		if (b->tail->value >= pv.p2)
		{
			rrb(b);
			pa(a, b);
			dsp.pa++;
		}
		else if (b->tail->value <= pv.p1)
		{
			rrb(b);
			dsp.rrb++;
		}
		else
		{
			rrb(b);
			pa(a, b);
			ra(a);
			dsp.ra++;
		}
		i++;
		printf("pivot : %d %d\n",pv.p1, pv.p2);
		print_deq(a, b, dsp);
	}
	stack = put_stack(a->head, dsp.pa);
	show(stack, dsp.pa);//
	ft_get_pivot(stack, &pv, dsp.pa);
	divide_ra(a, b, pv, dsp.pa);

	stack = put_stack2(a->tail, dsp.ra);
	show(stack, dsp.ra);//
	ft_get_pivot(stack, &pv, dsp.ra);
	divide_pbra(a, b, pv, dsp.ra);

	stack = put_stack(b->head, dsp.rrb);
	show(stack, dsp.rrb);//
	ft_get_pivot(stack, &pv, dsp.rrb);
	divide_pb(a, b, pv, dsp.rrb);
	
	printf("end rb\n");
}
