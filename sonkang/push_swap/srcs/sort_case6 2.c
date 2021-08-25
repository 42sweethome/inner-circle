/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_case6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonkang <sonkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 15:44:11 by sonkang           #+#    #+#             */
/*   Updated: 2021/06/17 15:55:59 by sonkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void		sub_only6(t_deq *a, t_deq *b, int pivot, t_dsp *dsp)
{
	int		idx;

	idx = 6;
	while (idx--)
	{
		if (a->head->value <= pivot)
		{
			pb(b, a);
			dsp->pb++;
		}
		else
		{
			ra(a);
			dsp->ra++;
		}
		if (dsp->pb == 3)
			break ;
	}
}

int			noly6(t_deq *a, t_deq *b, int *value)
{
	int		pivot;
	t_node	*temp;
	t_dsp	dsp;

	dsp_init(&dsp);
	pivot = ft_get_npivot(value, 5);
	sub_only6(a, b, pivot, &dsp);
	while (dsp.ra--)
		rra(a);
	sort_case3(a, b);
	while (dsp.pb--)
		pa(a, b);
	temp = a->head->next;
	sort_case3(a, b);
	return (0);
}

int			sort_case6(t_deq *a, t_deq *b)
{
	t_node	*temp;
	int		value[6];
	int		idx;

	temp = a->head;
	idx = 0;
	while (idx < 6)
	{
		value[idx++] = temp->value;
		temp = temp->next;
	}
	if (temp != NULL)
	{
		return (noly6(a, b, value));
	}
	return (1);
}
