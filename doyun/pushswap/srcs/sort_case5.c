/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_case5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <doyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 14:33:02 by doyun             #+#    #+#             */
/*   Updated: 2021/06/10 15:59:52 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int		only5(t_deq *a, t_deq *b, int *value)
{
	int		pivot;
	int		idx;
	t_node	*temp;

	idx = 5;
	pivot =	ft_get_5pivot(value);
	while(idx--)
	{
		if ( a->head->value < pivot)
		{
			pb(b, a);
		}
		else
		{
			ra(a);
		}
	}
	sort_case3(a, b);
	pa(a, b);
	pa(a, b);
	temp = a->head->next;
	if (a->head->value > temp->value)
		sa(a);
	return (0);
}

int		noly5(t_deq *a, t_deq *b, int *value)
{
	int		pivot;
	int		idx;
	t_node	*temp;
	t_dsp	dsp;

	idx = 5;
	dsp_init(&dsp);
	pivot =	ft_get_5pivot(value);
	while(idx--)
	{
		if ( a->head->value < pivot)
		{
			pb(b, a);
			dsp.pb++;
		}
		else
		{
			ra(a);
			dsp.ra++;
		}
		if (dsp.pb == 2)
			break;
	}
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


int		sort_case5(t_deq *a, t_deq *b)
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
	{
		return (only5(a, b, value));
	}
	else if (temp != NULL)
	{
		return (noly5(a, b, value));
	}
	return (0);
}
