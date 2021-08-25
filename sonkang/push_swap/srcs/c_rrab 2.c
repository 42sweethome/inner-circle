/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_rrab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonkang <sonkang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 18:02:37 by sonkang           #+#    #+#             */
/*   Updated: 2021/06/17 15:50:09 by sonkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void		crra(t_deq *a)
{
	t_node	*temp;

	if (a->head != NULL && a->head->next != NULL)
	{
		temp = a->tail->prev;
		temp->next = NULL;
		a->tail->next = a->head;
		a->head->prev = a->tail;
		a->tail->prev = NULL;
		a->head = a->tail;
		a->tail = temp;
	}
}

void		crrb(t_deq *b)
{
	t_node	*temp;

	if (b->head != NULL && b->head->next != NULL)
	{
		temp = b->tail->prev;
		temp->next = NULL;
		b->tail->next = b->head;
		b->head->prev = b->tail;
		b->tail->prev = NULL;
		b->head = b->tail;
		b->tail = temp;
	}
}

void		crrr(t_deq *a, t_deq *b)
{
	t_node	*temp;

	if (a->head != NULL && a->head->next != NULL)
	{
		temp = a->tail->prev;
		temp->next = NULL;
		a->tail->next = a->head;
		a->head->prev = a->tail;
		a->tail->prev = NULL;
		a->head = a->tail;
		a->tail = temp;
	}
	if (b->head != NULL && b->head->next != NULL)
	{
		temp = b->tail->prev;
		temp->next = NULL;
		b->tail->next = b->head;
		b->head->prev = b->tail;
		b->tail->prev = NULL;
		b->head = b->tail;
		b->tail = temp;
	}
}
