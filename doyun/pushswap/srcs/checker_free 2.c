/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <doyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 12:47:52 by doyun             #+#    #+#             */
/*   Updated: 2021/06/22 12:48:37 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void		ft_cdeqclear(t_node *node)
{
	t_node	*temp_node;

	if (!node)
		return ;
	while (node)
	{
		temp_node = node->next;
		free(node);
		node = temp_node;
	}
}

void		checker_free(t_buf *buf)
{
	if (buf->a != NULL)
	{
		if (buf->a->head != NULL)
			ft_cdeqclear(buf->a->head);
	}
	if (buf->b != NULL)
	{
		if (buf->b->head != NULL)
			ft_cdeqclear(buf->b->head);
	}
	if (buf->a != NULL)
		free(buf->a);
	if (buf->b != NULL)
		free(buf->b);
}
