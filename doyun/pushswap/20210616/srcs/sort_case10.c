/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_case7.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonkang <sonkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 21:06:45 by sonkang           #+#    #+#             */
/*   Updated: 2021/06/11 21:20:06 by sonkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int		noly10(t_deq *a, t_deq *b, int *value)
{
	int		pivot;
	int		idx;
	t_dsp	dsp;

	idx = 10;
	dsp_init(&dsp);
	pivot =	ft_get_npivot(value, 9);
	while(idx--)
	{
		if ( a->head->value <= pivot)
		{
			pb(b, a);
			dsp.pb++;
		}
		else
		{
			ra(a);
			dsp.ra++;
		}
		if (dsp.pb == 5)
			break;
	}
	while (dsp.ra--)
		rra(a);
	sort_case5(a, b);
	while (dsp.pb--)
		pa(a, b);
	sort_case5(a, b);
	return (0);
}


int		sort_case10(t_deq *a, t_deq *b)
{
	t_node	*temp;
	int		value[10];
	int		idx;

	temp = a->head;
	idx = 0;
	while (idx < 10)
	{
		value[idx++] = temp->value;
		temp = temp->next;
	}
	if (temp != NULL)
		return (noly10(a, b, value));
	return (1);
}
