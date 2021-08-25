/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_case4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <doyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 20:13:43 by doyun             #+#    #+#             */
/*   Updated: 2021/06/16 16:41:32 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int		only4(t_deq *a, t_deq *b, int *value)
{
	if (value[0] > value[1] && value[0] > value[2] && value[0] > value[3])
	{
		pb(b, a);
		sort_case3(a, b);
		pa(a, b);
		ra(a);
	}
	else if (value[0] < value[1] && value[0] < value[2] && value[0] < value[3])
	{
		pb(b, a);
		sort_case3(a, b);
		pa(a, b);
	}
	else if (value[3] < value[0] && value[3] < value[1] && value[3] < value[2])
	{
		rra(a);
		pb(b, a);
		sort_case3(a, b);
		pa(a, b);
	}
	else if (value[3] > value[0] && value[3] > value[1] && value[3] > value[2])
		sort_case3(a, b);
	else
		return (1);
	return (0);
}

void	only4_exception(t_deq *a, t_deq *b, int *value)
{
	if (value[0] > value[1] && value[2] > value[3] && value[0] < value[3])
	{
		pb(b, a);
		pb(b, a);
		ss(a, b);
		pa(a, b);
		pa(a, b);
	}
	else if (value[0] > value[2] && value[1] > value[3] && value[0] < value[3])
	{
		rra(a);
		sa(a);
		rra(a);
	}
	else if (value[0] < value[2] && value[1] < value[3] && value[0] > value[3])
	{
		ra(a);
		sa(a);
		ra(a);
	}
	else if (value[0] < value[1] && value[2] < value[3] && value[0] > value[3])
	{
		rra(a);
		rra(a);
	}
}

void	noly4(t_deq *a, t_deq *b)
{
	sa(a);
	pb(b, a);
	sa(a);
	pb(b, a);
	sa(a);
	pa(a, b);
	pa(a, b);
	sort_case3(a, b);
}

int		noly4_exception(t_deq *a, t_deq *b, int *value)
{
	if ((value[0] > value[1] && value[0] < value[2] && value[0] < value[3])
		|| (value[0] < value[1] && value[0] > value[2] && value[0] < value[3])
		|| (value[0] < value[1] && value[0] < value[2] && value[0] > value[3]))
	{
		pb(b, a);
		sort_case3(a, b);
		pa(a, b);
		sa(a);
	}
	else if (value[3] > value[0] && value[3] > value[1] && value[3] > value[2])
		sort_case3(a, b);
	else
		return (1);
	return (0);
}

int		sort_case4(t_deq *a, t_deq *b, int idx)
{
	t_node	*temp;
	int		value[4];

	temp = a->head;
	while (idx < 4)
	{
		value[idx++] = temp->value;
		temp = temp->next;
	}
	if (temp == NULL)
	{
		if (only4(a, b, value))
			only4_exception(a, b, value);
	}
	else if (temp != NULL)
	{
		if (value[0] > value[1] && value[0] > value[2] && value[0] > value[3])
		{
			noly4(a, b);
			return (0);
		}
		return (noly4_exception(a, b, value));
	}
	return (0);
}
