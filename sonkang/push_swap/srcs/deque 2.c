/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonkang <sonkang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 17:39:11 by sonkang           #+#    #+#             */
/*   Updated: 2021/06/17 15:50:51 by sonkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void		ft_create_buf(t_buf *buf)
{
	t_deq	*a;
	t_deq	*b;

	a = (t_deq *)malloc(sizeof(t_deq));
	b = (t_deq *)malloc(sizeof(t_deq));
	if (a != NULL)
		buf->a = a;
	if (b != NULL)
		buf->b = b;
}

void		ft_init(t_buf *buf)
{
	buf->a = NULL;
	buf->b = NULL;
	ft_create_buf(buf);
	buf->a->head = NULL;
	buf->a->tail = NULL;
	buf->b->head = NULL;
	buf->b->tail = NULL;
}

void		ft_create_deq(int *stack, t_deq *deq, int count)
{
	t_node	*new_node;
	int		i;

	i = -1;
	while (++i < count)
	{
		new_node = (t_node *)malloc(sizeof(t_node));
		new_node->prev = deq->tail;
		new_node->value = stack[i];
		new_node->next = NULL;
		if (deq->head == NULL)
			deq->head = new_node;
		else if (deq->head->next == NULL)
		{
			deq->head->next = new_node;
			new_node->prev = deq->head;
		}
		else
			deq->tail->next = new_node;
		deq->tail = new_node;
	}
}
