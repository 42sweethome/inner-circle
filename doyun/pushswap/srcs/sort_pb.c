/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_pb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <doyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 15:03:57 by doyun             #+#    #+#             */
/*   Updated: 2021/06/16 13:55:05 by doyun            ###   ########.fr       */
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
	else if (count == 2)
	{
		if (b->head->value < temp->value)
			sb(b);
		while (count--)
			pa(a, b);
	}
	else
	{
		rs_case3(a, b);
	}
}

void	divide_pb(t_deq *a, t_deq *b, t_pivot pv, int count)
{
	printf("\nstart pb\n");
	t_dsp dsp;
	int i;
	int	*stack;
	/*	t_node *tmp;

		i = 0;
		tmp = b->head;
		while (i++ < count && (tmp != NULL && tmp->next != NULL))
		{
		if (tmp->value < tmp->next->value)
		break;
		tmp = tmp->next;
		if (tmp == NULL || i == count)
		return ;
		}*/
	i = 0;
	dsp_init(&dsp);
	if (ft_check_bhead(b, count))
	{
		while (i++ < count)
			pa(a, b);
		return ;
	}
	//	printf("pb 범인 : %d %d %d\n",pv.p1, pv.p2, count);
	if (count <= 3)
	{
		//		divide_rrr(a, b, pdsp);
		last_sort_pb(a, b, count);
		//		print_deq(a, b, dsp);
		//		printf("pb out\n");
		return ;

	}
/*	if (count <= 5)
	{
		while (i++ < count)
		{
			pa(a, b);
		}
		stack = put_stack(a->head, count);
//		show(stack, dsp.ra);
		ft_get_pivot(stack, &pv, count);
		divide_ra(a, b, pv, count, dsp);

	}
*/
	while(i < count)
	{
		if (b->head->value >= pv.p2)
		{
			pa(a, b);
			dsp.pa++;
		}
		else if (b->head->value <= pv.p1)
		{
			/*	pa(a, b);
				ra(a);
				dsp.ra++;*/
			rb(b);
			dsp.rb++;

		}
		else
		{
			pa(a, b);
			ra(a);
			dsp.ra++;
			/*	rb(b);
				dsp.rb++;*/
		}
		i++;
		//		printf("pivot : %d %d\n",pv.p1, pv.p2);
		print_deq(a, b, dsp);
	}


	printf("end pb\n");
	stack = put_stack(a->head, dsp.pa);
	show(stack, dsp.pa);
	ft_get_pivot(stack, &pv, dsp.pa);
	divide_ra(a, b, pv, dsp.pa, dsp);

	if (dsp.ra || dsp.rb)
	{
		divide_rrr(a, b, dsp);
		if (!(ft_check_ahead(a, dsp.ra)))
		{
			stack = put_stack(a->head, dsp.ra);
			show(stack, dsp.ra);
			ft_get_pivot(stack, &pv, dsp.ra);
			divide_ra(a, b, pv, dsp.ra, dsp);
		}
	}

	stack = put_stack(b->head, dsp.rb);
	show(stack, dsp.rb);
	ft_get_pivot(stack, &pv, dsp.rb);	
	//printf("--count %d\n", dsp.ra);
	divide_pb(a, b, pv, dsp.rb);

/*	stack = put_stack(b->head, dsp.pb);
//	show(stack, dsp.pb);
	ft_get_pivot(stack, &pv, dsp.pb);	
	//printf("--count %d\n", dsp.ra);
	divide_pb(a, b, pv, dsp.pb);
*/
}
