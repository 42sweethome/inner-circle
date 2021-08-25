/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_link.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 14:42:37 by junghan           #+#    #+#             */
/*   Updated: 2021/04/26 20:07:45 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"


void	lstadd_back(t_circle **head, t_circle **tail,t_circle *new)
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
		return(0);
	node->value = content;
	node->next = NULL;
	node->pre = NULL;
	return (node);
}
