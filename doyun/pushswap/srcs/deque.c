/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <doyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 17:39:11 by doyun             #+#    #+#             */
/*   Updated: 2021/06/16 18:03:35 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void		ft_init(t_deq *a, t_deq *b)
{
	a->head = NULL;
	a->tail = NULL;
	b->head = NULL;
	b->tail = NULL;
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

int			ft_deqlen(t_deq deq)
{
	int		len;

	len = 0;
	while (deq.head != NULL)
	{
		deq.head = deq.head->next;
		len++;
	}
	return (len);
}
