/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ra.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <doyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 15:03:10 by doyun             #+#    #+#             */
/*   Updated: 2021/06/09 17:24:32 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void		last_sort_ra(t_deq *a, t_deq *b, int count)
{
	t_node	*temp;
	t_node	*temp_next;
	int		i;

	temp = a->head->next;
	temp_next = temp->next;
	i = 0;
/*	while (i++ < count)
		rra(a);*/
	if (count == 2)
	{
		if (a->head->value > temp->value)
		{
			sa(a);
		}
	}
	else if (count == 3)
	{
		printf("before :%d %d %d\n", a->head->value, temp->value, temp_next->value);
		if (a->head->value > temp->value)
		{
			if (a->head->value > temp_next->value)
			{
				if (temp->value > temp_next->value)
				{
					pb(b, a);
					ra(a);
					pa(a, b);
					sa(a);
					rra(a);
					sa(a);
				}
				else if (temp->value < temp_next->value)
				{
					pb(b, a);
					ra(a);
					pa(a, b);
					sa(a);
					rra(a);
				}
			}
			else if (a->head->value < temp_next->value)
			{
				sa(a);	
			}
		}
		else if (a->head->value < temp->value)
		{
			if (a->head->value > temp_next->value)
			{
				if (temp->value > temp_next->value)
				{
					pb(b, a);
					sa(a);
					pa(a, b);
					sa(a);
				}
			}
			else if (a->head->value < temp_next->value)
			{
				if (temp->value > temp_next->value)
				{
					pb(b, a);
					sa(a);
					pa(a, b);
					
				}
			}
		}
		printf("after :%d %d %d\n", a->head->value, temp->value, temp_next->value);
	}
}


void		divide_ra(t_deq *a, t_deq *b, t_pivot pv, int count)
{
	printf("\nstart ra\n");
	t_dsp dsp;
	int i;
	int	*stack;
/*	t_node *tmp;

	i = 0;
	tmp = a->head;
	while (i++ < count && (tmp != NULL && tmp->next != NULL))
	{
		if (tmp->value > tmp->next->value)
			break;
		tmp = tmp->next;
		if (tmp == NULL || i == count)
			return ;
	}*/
	i = 0;
	if (count == 0)
		return ;
	else if (count == 1)
		return ;
	else if (count <= 3)
	{
		last_sort_ra(a, b, count);
		dsp_init(&dsp);
		print_deq(a, b, dsp);
		printf("ra out\n");
		return ;
	}
	dsp_init(&dsp);
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
			rb(b);
			dsp.rb++;
		}
		else 
		{
			pb(b, a);
			dsp.pb++;
		}
		i++;
		printf("pivot : %d %d\n",pv.p1, pv.p2);
		print_deq(a, b, dsp);
	}
/*	i = 0;
	while (i++ < dsp.ra)
		rra(a);*/
	stack = put_stack2(a->tail, dsp.ra);
	show(stack, dsp.ra);//
	ft_get_pivot(stack, &pv, dsp.ra);
	divide_pbra(a, b, pv, dsp.ra);

	stack = put_stack(b->head, dsp.pb);
	show(stack, dsp.pb);//
	ft_get_pivot(stack, &pv, dsp.pb);
	divide_pb(a, b, pv, dsp.pb);

	stack = put_stack2(b->tail, dsp.rb);
	show(stack, dsp.rb);//
	ft_get_pivot(stack, &pv, dsp.rb);
	divide_rb(a, b, pv, dsp.rb);
}
