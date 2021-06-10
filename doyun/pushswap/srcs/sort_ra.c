/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ra.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <doyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 15:03:10 by doyun             #+#    #+#             */
/*   Updated: 2021/06/10 16:56:19 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void		divide_ra(t_deq *a, t_deq *b, t_pivot pv, int count)
{
//	printf("\nstart ra\n");
	t_dsp dsp;
	int i;
	int	*stack;
	int	check;

	i = 0;
	check = 0;
//	if (ft_check_sort(a, count))
//		return ;
	if (count <= 5)
	{
		check = sort_case(a, b, count);
		if (check == 0)
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
		//printf("pivot : %d %d\n",pv.p1, pv.p2);
//				print_deq(a, b, dsp);
	}
	stack = put_stack2(a->tail, dsp.ra);
//	show(stack, dsp.ra);//
	ft_get_pivot(stack, &pv, dsp.ra);
	divide_pbra(a, b, pv, dsp.ra);

	stack = put_stack(b->head, dsp.pb);
//	show(stack, dsp.pb);//
	ft_get_pivot(stack, &pv, dsp.pb);
	divide_pb(a, b, pv, dsp.pb);

	stack = put_stack2(b->tail, dsp.rb);
//	show(stack, dsp.rb);//
	ft_get_pivot(stack, &pv, dsp.rb);
	divide_rb(a, b, pv, dsp.rb);
}
