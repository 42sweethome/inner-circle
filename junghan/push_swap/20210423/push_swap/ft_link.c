/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_link.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 14:42:37 by junghan           #+#    #+#             */
/*   Updated: 2021/04/23 16:00:19 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"


void	lstadd_back(t_circle **lst, t_circle *new)
{
	t_circle	*tmp;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	new->next = tmp->next;
	tmp->next = new;//pre해줘야
}

t_circle	*lstnew(int content)
{
	t_circle	*node;

	if (!(node = (t_circle *)ft_calloc(1, sizeof(t_circle))))
		return(0);
	node->value = content;
	node->next = NULL;
	node->pre = NULL;
	return (node);
}
