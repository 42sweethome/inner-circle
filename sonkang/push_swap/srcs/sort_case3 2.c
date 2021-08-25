/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_case3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonkang <sonkang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 16:50:57 by sonkang           #+#    #+#             */
/*   Updated: 2021/06/17 15:55:35 by sonkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void		only3_big_head(t_deq *a)
{
	t_node	*temp;
	t_node	*temp_next;

	temp = a->head->next;
	temp_next = temp->next;
	if (a->head->value > temp_next->value)
	{
		if (temp->value > temp_next->value)
		{
			sa(a);
			rra(a);
		}
		else if (temp->value < temp_next->value)
			ra(a);
	}
	else if (a->head->value < temp_next->value)
		sa(a);
}

void		only3_big_temp(t_deq *a)
{
	t_node	*temp;
	t_node	*temp_next;

	temp = a->head->next;
	temp_next = temp->next;
	if (a->head->value > temp_next->value)
		rra(a);
	else if (a->head->value < temp_next->value)
	{
		if (temp->value > temp_next->value)
		{
			sa(a);
			ra(a);
		}
	}
}

void		noly3_big_head(t_deq *a, t_deq *b, t_node *temp, t_node *temp_next)
{
	if (a->head->value > temp_next->value)
	{
		if (temp->value > temp_next->value)
		{
			pb(b, a);
			ra(a);
			pa(a, b);
			sa(a);
			rra(a);
			sa(a);
		}
		else if (temp->value < temp_next->value)
		{
			pb(b, a);
			ra(a);
			pa(a, b);
			sa(a);
			rra(a);
		}
	}
	else if (a->head->value < temp_next->value)
		sa(a);
}

void		noly3_big_temp(t_deq *a, t_deq *b)
{
	t_node	*temp;
	t_node	*temp_next;

	temp = a->head->next;
	temp_next = temp->next;
	if (a->head->value > temp_next->value)
	{
		if (temp->value > temp_next->value)
		{
			pb(b, a);
			sa(a);
			pa(a, b);
			sa(a);
		}
	}
	else if (a->head->value < temp_next->value)
	{
		if (temp->value > temp_next->value)
		{
			pb(b, a);
			sa(a);
			pa(a, b);
		}
	}
}

int			sort_case3(t_deq *a, t_deq *b)
{
	t_node	*temp;
	t_node	*temp_next;

	temp = a->head->next;
	temp_next = temp->next;
	if (temp_next->next == NULL)
	{
		if (a->head->value > temp->value)
			only3_big_head(a);
		else if (a->head->value < temp->value)
			only3_big_temp(a);
		return (0);
	}
	if (a->head->value > temp->value)
		noly3_big_head(a, b, temp, temp_next);
	else if (a->head->value < temp->value)
		noly3_big_temp(a, b);
	return (0);
}
