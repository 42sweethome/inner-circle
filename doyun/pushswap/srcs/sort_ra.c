/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ra.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <doyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 15:03:10 by doyun             #+#    #+#             */
/*   Updated: 2021/06/08 18:36:13 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void		last_sort_ra(t_deq *deq, int count)
{
	t_node	*temp;
	int		i;

	temp = deq->head->next;
	i = 0;
//	while (i++ < count)
//		rra(deq);
	if (count > 1)
	{
		if (deq->head->value > temp->value)
		{
			sa(deq);
		}
	}
}

//void		case_count(int count, t_deq *a, t_deq *b, t_dsp dsp, t_pivot pv)
//{
	
//}

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
	else if (count == 2)
	{
		last_sort_ra(a, count);
		dsp_init(&dsp);
		print_deq(a, b, dsp);
		printf("ra out\n");
		return ;
	}
	dsp_init(&dsp);
	while(i < count)
	{
		if (a->head->value >= pv.p2) //큰 숫자 ra
		{
			ra(a);
			dsp.ra++;
		}
		else if (a->head->value <= pv.p1) //작은 숫자 rb
		{
			pb(b, a);
			rb(b);
			dsp.rb++;
		}
		else //중간 숫자 pb
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
