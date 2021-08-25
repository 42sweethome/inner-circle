/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ra.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <doyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 15:03:10 by doyun             #+#    #+#             */
/*   Updated: 2021/06/17 11:36:16 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void		start_divide_ra(t_buf *buf, t_pivot pv, int count, t_dsp *dsp)
{
	int		i;

	i = 0;
	while (i < count)
	{
		if (buf->a->head->value >= pv.p2)
		{
			ra(buf->a);
			dsp->ra++;
		}
		else if (buf->a->head->value <= pv.p1)
		{
			pb(buf->b, buf->a);
			dsp->pb++;
		}
		else
		{
			pb(buf->b, buf->a);
			rb(buf->b);
			dsp->rb++;
		}
		i++;
	}
}

void		recursive_ra(t_buf *buf, t_dsp *dsp, t_pivot pv, t_dsp pdsp)
{
	int		*stack;

	if (dsp->ra || dsp->rb)
		divide_rrr(buf->a, buf->b, *dsp);
	stack = put_stack(buf->a->head, dsp->ra);
	ft_get_pivot(stack, &pv, dsp->ra);
	divide_ra(buf, pv, dsp->ra, pdsp);
	stack = put_stack(buf->b->head, dsp->rb);
	ft_get_pivot(stack, &pv, dsp->rb);
	divide_pb(buf, pv, dsp->rb);
	stack = put_stack(buf->b->head, dsp->pb);
	ft_get_pivot(stack, &pv, dsp->pb);
	divide_pb(buf, pv, dsp->pb);
}

void		divide_ra(t_buf *buf, t_pivot pv, int count, t_dsp pdsp)
{
	t_dsp	dsp;
	int		i;
	int		check;

	i = 0;
	check = 0;
	if (ft_check_ahead(buf->a, count))
		return ;
	if (count <= 6)
	{
		check = sort_case(buf->a, buf->b, count);
		if (check == 0)
			return ;
	}
	dsp_init(&dsp);
	start_divide_ra(buf, pv, count, &dsp);
	recursive_ra(buf, &dsp, pv, pdsp);
}
