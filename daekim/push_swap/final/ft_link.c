/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_link.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 12:37:35 by daekim            #+#    #+#             */
/*   Updated: 2021/05/23 12:37:36 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void		lstclear(t_circle **head, t_circle **tail)
{
	t_circle	*tmp;

	if (!(*head) || !head)
		return ;
	tmp = (*head);
	while (*head)
	{
		tmp = (*head)->next;
		(*head)->next = NULL;
		(*head)->pre = NULL;
		(*head)->value = 0;
		free(*head);
		(*head) = NULL;
		(*head) = tmp;
	}
	head = NULL;
	tail = NULL;
}

void		lstadd_back(t_circle **head, t_circle **tail, t_circle *new)
{
	t_circle	*tmp;

	if (!new)
		return ;
	if (!*head)
	{
		*head = new;
		*tail = new;
		return ;
	}
	tmp = *head;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	new->next = tmp->next;
	tmp->next = new;
	new->pre = tmp;
	*tail = new;
}

t_circle	*lstnew(int content, int *len)
{
	t_circle	*node;

	(*len)++;
	if (!(node = (t_circle *)ft_calloc(1, sizeof(t_circle))))
		return (0);
	node->value = content;
	node->next = NULL;
	node->pre = NULL;
	return (node);
}
