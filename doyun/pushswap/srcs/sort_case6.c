/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_case6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonkang <sonkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 15:44:11 by sonkang           #+#    #+#             */
/*   Updated: 2021/06/14 20:44:35 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"
/*
int		only6(t_deq *a, t_deq *b, int *value)
{
	int		pivot;
	int		idx;
	t_node	*temp;

	idx = 6;
	pivot =	ft_get_npivot(value, 5);
	while(idx--)
	{
		if ( a->head->value <= pivot)
		{
			pb(b, a);
		}
		else
			ra(a);
	}
	sort_case3(a, b);
	pa(a, b);
	pa(a, b);
	temp = a->head->next;
	if (a->head->value > temp->value)
		sa(a);
	pa(a, b);
	if (a->head->value > temp->value)
		sa(a);
	return (0);
}
*/
int		noly6(t_deq *a, t_deq *b, int *value)
{
	int		pivot;
	int		idx;
	t_node	*temp;
	t_dsp	dsp;

	idx = 6;
	dsp_init(&dsp);
	pivot =	ft_get_npivot(value, 5);
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
		if (dsp.pb == 3)
			break;
	}
	while (dsp.ra--)
		rra(a);
	sort_case3(a, b);
	while (dsp.pb--)
		pa(a, b);
	temp = a->head->next;
	sort_case3(a, b);
	return (0);
}

int		sort_case6(t_deq *a, t_deq *b)
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
/*	if (temp == NULL)
	{
		return (only6(a, b, value));
	}
*/	if (temp != NULL)
	{
		return (noly6(a, b, value));
	}
	return (1);
}
