/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_pb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <doyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 15:03:57 by doyun             #+#    #+#             */
/*   Updated: 2021/06/16 14:27:23 by doyun            ###   ########.fr       */
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
	t_dsp dsp;
	int i;
	int	*stack;

	i = 0;
	dsp_init(&dsp);
	if (ft_check_bhead(b, count))
	{
		while (i++ < count)
			pa(a, b);
		return ;
	}
	if (count <= 3)
	{
		last_sort_pb(a, b, count);
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
//		print_deq(a, b, dsp);
	}


//	printf("end pb\n");
	stack = put_stack(a->head, dsp.pa);
//	show(stack, dsp.pa);
	ft_get_pivot(stack, &pv, dsp.pa);
	divide_ra(a, b, pv, dsp.pa, dsp);

	if (dsp.ra || dsp.rb)
	{
		divide_rrr(a, b, dsp);
		if (!(ft_check_ahead(a, dsp.ra)))
		{
			stack = put_stack(a->head, dsp.ra);
	//		show(stack, dsp.ra);
			ft_get_pivot(stack, &pv, dsp.ra);
			divide_ra(a, b, pv, dsp.ra, dsp);
		}
	}

	stack = put_stack(b->head, dsp.rb);
//	show(stack, dsp.rb);
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
