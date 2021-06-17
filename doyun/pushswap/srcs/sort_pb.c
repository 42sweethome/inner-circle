/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_pb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <doyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 15:03:57 by doyun             #+#    #+#             */
/*   Updated: 2021/06/16 20:43:20 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void		last_sort_pb(t_buf *buf, int count)
{
	t_node	*temp;

	temp = buf->b->head->next;
	if (count == 0)
		return ;
	else if (count == 1)
		pa(buf->a, buf->b);
	else if (count == 2)
	{
		if (buf->b->head->value < temp->value)
			sb(buf->b);
		while (count--)
			pa(buf->a, buf->b);
	}
	else
	{
		rs_case3(buf->a, buf->b);
	}
}

void		start_divide_pb(t_buf *buf, t_pivot pv, int count, t_dsp *dsp)
{
	int		i;

	i = 0;
	while (i < count)
	{
		if (buf->b->head->value >= pv.p2)
		{
			pa(buf->a, buf->b);
			dsp->pa++;
		}
		else if (buf->b->head->value <= pv.p1)
		{
			rb(buf->b);
			dsp->rb++;
		}
		else
		{
			pa(buf->a, buf->b);
			ra(buf->a);
			dsp->ra++;
		}
		i++;
	}
}

void		recursive_pb(t_buf *buf, t_dsp *dsp, t_pivot pv)
{
	int		*stack;

	stack = put_stack(buf->a->head, dsp->pa);
	ft_get_pivot(stack, &pv, dsp->pa);
	divide_ra(buf, pv, dsp->pa, *dsp);
	if (dsp->ra || dsp->rb)
	{
		divide_rrr(buf->a, buf->b, *dsp);
		if (!(ft_check_ahead(buf->a, dsp->ra)))
		{
			stack = put_stack(buf->a->head, dsp->ra);
			ft_get_pivot(stack, &pv, dsp->ra);
			divide_ra(buf, pv, dsp->ra, *dsp);
		}
	}
	stack = put_stack(buf->b->head, dsp->rb);
	ft_get_pivot(stack, &pv, dsp->rb);
	divide_pb(buf, pv, dsp->rb);
}

void		divide_pb(t_buf *buf, t_pivot pv, int count)
{
	t_dsp	dsp;
	int		i;

	i = 0;
	dsp_init(&dsp);
	if (ft_check_bhead(buf->b, count))
	{
		while (i++ < count)
			pa(buf->a, buf->b);
		return ;
	}
	if (count <= 3)
	{
		last_sort_pb(buf, count);
		return ;
	}
	start_divide_pb(buf, pv, count, &dsp);
	recursive_pb(buf, &dsp, pv);
}
