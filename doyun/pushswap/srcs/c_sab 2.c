/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_sab.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <doyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 14:58:57 by doyun             #+#    #+#             */
/*   Updated: 2021/06/17 14:58:58 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void		csa(t_deq *a)
{
	t_node	*temp;
	t_node	*temp_next;

	if (a->head != NULL && a->head->next != NULL)
	{
		temp = a->head->next;
		temp_next = temp->next;
		a->head->next = temp_next;
		if (temp_next != NULL)
			temp_next->prev = a->head;
		if (temp->next == NULL)
			a->tail = a->head;
		temp->next = a->head;
		a->head->prev = temp;
		temp->prev = NULL;
		a->head = temp;
	}
}

void		csb(t_deq *b)
{
	t_node	*temp;
	t_node	*temp_next;

	if (b->head != NULL && b->head->next != NULL)
	{
		temp = b->head->next;
		temp_next = temp->next;
		b->head->next = temp_next;
		if (temp_next != NULL)
			temp_next->prev = b->head;
		if (temp->next == NULL)
			b->tail = b->head;
		temp->next = b->head;
		b->head->prev = temp;
		temp->prev = NULL;
		b->head = temp;
	}
}

void		css(t_deq *a, t_deq *b)
{
	if ((a->head != NULL && a->head->next != NULL) ||
			(b->head != NULL && b->head->next != NULL))
	{
		csa(a);
		csb(b);
	}
}
