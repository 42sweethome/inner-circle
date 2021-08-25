/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <doyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 16:43:28 by doyun             #+#    #+#             */
/*   Updated: 2021/06/16 18:01:52 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int			*ft_check_dup(int *stack, int count)
{
	int		*temp;

	temp = stack;
	if (stack == NULL)
		return (NULL);
	while (--count)
	{
		if (ft_memchr(temp, *temp, count))
			return (NULL);
		temp++;
	}
	return (stack);
}

int			ft_check_ahead(t_deq *deq, int count)
{
	t_node	*temp;
	t_node	*temp_next;

	temp = deq->head;
	if (temp != NULL)
		temp_next = temp->next;
	while (--count > 0)
	{
		if (temp->value < temp_next->value)
		{
			temp = temp_next;
			temp_next = temp_next->next;
		}
		else
			return (0);
	}
	return (1);
}

int			ft_check_atail(t_deq *deq, int count)
{
	t_node	*temp;
	t_node	*temp_prev;

	temp = deq->tail;
	if (temp != NULL)
		temp_prev = temp->prev;
	while (--count > 0)
	{
		if (temp->value > temp_prev->value && temp != NULL && temp_prev != NULL)
		{
			temp = temp_prev;
			temp_prev = temp_prev->prev;
		}
		else
			return (0);
	}
	return (1);
}

int			ft_check_bhead(t_deq *deq, int count)
{
	t_node	*temp;
	t_node	*temp_next;

	temp = deq->head;
	if (temp != NULL)
		temp_next = temp->next;
	while (--count && count > 0)
	{
		if (temp->value > temp_next->value)
		{
			temp = temp_next;
			temp_next = temp_next->next;
		}
		else
			return (0);
	}
	return (1);
}

int			ft_check_btail(t_deq *deq, int count)
{
	t_node	*temp;
	t_node	*temp_prev;

	temp = deq->tail;
	if (temp != NULL)
		temp_prev = temp->prev;
	while (--count)
	{
		if (temp->value > temp_prev->value)
		{
			temp = temp_prev;
			temp_prev = temp_prev->prev;
		}
		else
			return (0);
	}
	return (1);
}
