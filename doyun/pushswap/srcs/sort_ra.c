/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ra.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <doyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 15:03:10 by doyun             #+#    #+#             */
/*   Updated: 2021/06/16 14:26:46 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void		divide_ra(t_deq *a, t_deq *b, t_pivot pv, int count, t_dsp pdsp)
{
	t_dsp dsp;
	int i;
	int	*stack;
	int	check;

	i = 0;
	check = 0;
	if (ft_check_ahead(a, count))
		return ;
	if (count <= 6)
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
			dsp.pb++;	
		}
		else 
		{
			pb(b, a);
			rb(b);
			dsp.rb++;
		}
		i++;
	}
	if (dsp.ra || dsp.rb)
			divide_rrr(a, b, dsp);
	stack = put_stack(a->head, dsp.ra);
	ft_get_pivot(stack, &pv, dsp.ra);
	divide_ra(a, b, pv, dsp.ra, pdsp);

	stack = put_stack(b->head, dsp.rb);
	ft_get_pivot(stack, &pv, dsp.rb);
	divide_pb(a, b, pv, dsp.rb);
	
	stack = put_stack(b->head, dsp.pb);
	ft_get_pivot(stack, &pv, dsp.pb);
	divide_pb(a, b, pv, dsp.pb);
}
