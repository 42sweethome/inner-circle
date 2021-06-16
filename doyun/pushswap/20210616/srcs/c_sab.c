/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_sab.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonkang <sonkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 17:27:24 by sonkang           #+#    #+#             */
/*   Updated: 2021/06/11 19:49:33 by sonkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void		csa(t_deq *a)
{
	t_node	*temp;
	if (a->head != NULL && a->head->next != NULL)
	{
		temp = a->head->next;	
		a->head->next = temp->next;
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

	if (b->head != NULL && b->head->next != NULL)
	{
		temp = b->head->next;
		b->head->next = temp->next;
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
	t_node	*temp;

	if (a->head != NULL && a->head->next != NULL)
	{
		temp = a->head->next;	
		a->head->next = temp->next;
		if (temp->next == NULL)
			a->tail = a->head;
		temp->next = a->head;	
		a->head->prev = temp;	
		temp->prev = NULL;	
		a->head = temp;	
	}
	if (b->head != NULL && b->head->next != NULL)
	{
		temp = b->head->next;
		b->head->next = temp->next;
		if (temp->next == NULL)
			b->tail = b->head;
		temp->next = b->head;
		b->head->prev = temp;
		temp->prev = NULL;
		b->head = temp;
	}
}
