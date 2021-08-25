/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_case5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <doyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 14:33:02 by doyun             #+#    #+#             */
/*   Updated: 2021/06/17 11:20:07 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void		sub_only5(t_deq *a, t_deq *b, int pivot)
{
	int		idx;
	t_dsp	dsp;

	dsp_init(&dsp);
	idx = 5;
	while (idx--)
	{
		if (a->head->value < pivot)
		{
			pb(b, a);
			dsp.pb++;
		}
		else
			ra(a);
		if (dsp.pb == 2)
			break ;
	}
}

int			only5(t_deq *a, t_deq *b, int *value)
{
	int		pivot;
	t_node	*temp;

	pivot = ft_get_npivot(value, 4);
	sub_only5(a, b, pivot);
	sort_case3(a, b);
	pa(a, b);
	pa(a, b);
	temp = a->head->next;
	if (a->head->value > temp->value)
		sa(a);
	return (0);
}

void		sub_noly5(t_deq *a, t_deq *b, int pivot, t_dsp *dsp)
{
	int		idx;

	idx = 5;
	while (idx--)
	{
		if (a->head->value < pivot)
		{
			pb(b, a);
			dsp->pb++;
		}
		else
		{
			ra(a);
			dsp->ra++;
		}
		if (dsp->pb == 2)
			break ;
	}
}

int			noly5(t_deq *a, t_deq *b, int *value)
{
	int		pivot;
	t_node	*temp;
	t_dsp	dsp;

	dsp_init(&dsp);
	pivot = ft_get_npivot(value, 4);
	sub_noly5(a, b, pivot, &dsp);
	while (dsp.ra--)
		rra(a);
	sort_case3(a, b);
	while (dsp.pb--)
		pa(a, b);
	temp = a->head->next;
	if (a->head->value > temp->value)
		sa(a);
	return (0);
}

int			sort_case5(t_deq *a, t_deq *b)
{
	t_node	*temp;
	int		value[5];
	int		idx;

	temp = a->head;
	idx = 0;
	while (idx < 5)
	{
		value[idx++] = temp->value;
		temp = temp->next;
	}
	if (temp == NULL)
		return (only5(a, b, value));
	else if (temp != NULL)
		return (noly5(a, b, value));
	return (0);
}
