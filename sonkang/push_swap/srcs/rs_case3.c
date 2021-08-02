/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs_case3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonkang <sonkang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 20:53:27 by sonkang           #+#    #+#             */
/*   Updated: 2021/06/17 15:54:53 by sonkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void		sub_rs3_big_head(t_deq *a, t_deq *b)
{
	t_node	*temp;
	t_node	*temp_next;

	temp = b->head->next;
	temp_next = temp->next;
	if (temp->value > temp_next->value)
	{
		pa(a, b);
		pa(a, b);
		pa(a, b);
	}
	else if (temp->value < temp_next->value)
	{
		pa(a, b);
		sb(b);
		pa(a, b);
		pa(a, b);
	}
}

void		rs3_big_head(t_deq *a, t_deq *b)
{
	t_node	*temp;
	t_node	*temp_next;

	temp = b->head->next;
	temp_next = temp->next;
	if (b->head->value > temp_next->value)
		sub_rs3_big_head(a, b);
	else if (b->head->value < temp_next->value)
	{
		pa(a, b);
		sb(b);
		pa(a, b);
		sa(a);
		pa(a, b);
	}
}

void		sub_rs3_big_temp(t_deq *a, t_deq *b)
{
	t_node	*temp;
	t_node	*temp_next;

	temp = b->head->next;
	temp_next = temp->next;
	if (temp->value > temp_next->value)
	{
		sb(b);
		pa(a, b);
		sb(b);
		pa(a, b);
		pa(a, b);
	}
	else if (temp->value < temp_next->value)
	{
		sb(b);
		pa(a, b);
		sb(b);
		pa(a, b);
		sa(a);
		pa(a, b);
	}
}

void		rs3_big_temp(t_deq *a, t_deq *b)
{
	t_node	*temp;
	t_node	*temp_next;

	temp = b->head->next;
	temp_next = temp->next;
	if (b->head->value > temp_next->value)
	{
		if (temp->value > temp_next->value)
		{
			sb(b);
			pa(a, b);
			pa(a, b);
			pa(a, b);
		}
	}
	else if (b->head->value < temp_next->value)
		sub_rs3_big_temp(a, b);
}

int			rs_case3(t_deq *a, t_deq *b)
{
	t_node	*temp;
	t_node	*temp_next;

	temp = b->head->next;
	temp_next = temp->next;
	if (b->head->value > temp->value)
		rs3_big_head(a, b);
	else if (b->head->value < temp->value)
		rs3_big_temp(a, b);
	return (0);
}
