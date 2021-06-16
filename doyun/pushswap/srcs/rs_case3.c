/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs_case3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <doyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 20:53:27 by doyun             #+#    #+#             */
/*   Updated: 2021/06/16 14:12:11 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	rs3_big_head(t_deq *a, t_deq *b)
{
	t_node	*temp;
	t_node	*temp_next;

	temp = b->head->next;
	temp_next = temp->next;
	if (b->head->value > temp_next->value)
	{
		if (temp->value > temp_next->value)//321
		{
			pa(a, b);
			pa(a, b);
			pa(a, b);
		}
		else if (temp->value < temp_next->value)//312
		{
			pa(a, b);
			sb(b);
			pa(a, b);
			pa(a, b);
		}
	}
	else if (b->head->value < temp_next->value)//213
	{
		pa(a, b);
		sb(b);
		pa(a, b);
		sa(a);
		pa(a, b);
	}
}

void	rs3_big_temp(t_deq *a, t_deq *b)
{
	t_node	*temp;
	t_node	*temp_next;

	temp = b->head->next;
	temp_next = temp->next;
	if (b->head->value > temp_next->value)
	{
		if (temp->value > temp_next->value)//231
		{
			sb(b);
			pa(a, b);
			pa(a, b);
			pa(a, b);
		}
	}
	else if (b->head->value < temp_next->value)
	{
		if (temp->value > temp_next->value)//132
		{
			sb(b);
			pa(a, b);
			sb(b);
			pa(a, b);
			pa(a, b);
		}
		else if (temp->value < temp_next->value)//123
		{
			sb(b);
			pa(a, b);
			sb(b);
			pa(a, b);
			sa(a);
			pa(a, b);
		}
	}
}
int		rs_case3(t_deq *a, t_deq *b)
{
	t_node	*temp;
	t_node	*temp_next;

	temp = b->head->next;
	temp_next = temp->next;
/*	if (temp_next->next == NULL)
	{
		
	}
	else if (temp_next->next != NULL)
	{*/
		if (b->head->value > temp->value)
			rs3_big_head(a, b);		
		else if (b->head->value < temp->value)
			rs3_big_temp(a, b);
	//}

	return (0);

}
