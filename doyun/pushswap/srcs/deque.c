/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <doyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 17:39:11 by doyun             #+#    #+#             */
/*   Updated: 2021/05/31 14:54:19 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	ft_deq_init(t_deq *A, t_deq *B)
{
	A->head = NULL;
	A->tail = NULL;
	B->head = NULL;
	B->tail = NULL;
}

void	ft_create_deq(int value, t_deq *deq)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	new_node->prev = deq->tail;
	new_node->value = value;
	new_node->next = NULL;
	if (deq->head == NULL)
	{
		deq->head = new_node;
		printf("crate head : %d\n", new_node->value);
	}
	else if (deq->head->next == NULL)
	{
		deq->head->next = new_node;
		new_node->prev = deq->head;
	}
	else
	{
		deq->tail->next = new_node;
	}
	deq->tail = new_node;
	printf("create tail : %d\n", deq->tail->value);
}

int		ft_deqlen(t_deq deq)
{
	int	len;

	len = 0;
	while (deq.head != NULL)
	{
		deq.head = deq.head->next;
		len++;
	}
	return (len);
}

