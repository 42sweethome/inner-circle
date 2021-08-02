/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonkang <sonkang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 18:01:36 by sonkang           #+#    #+#             */
/*   Updated: 2021/06/22 20:09:30 by sonkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void		start_sort(t_buf buf, t_pivot pv, int count)
{
	t_dsp	dsp;

	dsp_init(&dsp);
	divide_ra(&buf, pv, count, dsp);
}

void		ft_deqclear(t_node *node)
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

void		ft_free(t_buf *buf)
{
	if (buf->a != NULL)
	{
		if (buf->a->head != NULL)
			ft_deqclear(buf->a->head);
	}
	if (buf->b != NULL)
	{
		if (buf->b->head != NULL)
			ft_deqclear(buf->b->head);
	}
	if (buf->a != NULL)
		free(buf->a);
	if (buf->b != NULL)
		free(buf->b);
}

int			main(int argc, char **argv)
{
	int		count;
	int		*stack;
	t_pivot pv;
	t_buf	buf;

	if (argc <= 1)
		return (0);
	if ((count = ft_count_arg(argv, ' ')) == 0)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	stack = ft_get_sortstack(argc, argv, count);
	stack = ft_check_dup(stack, count);
	if (stack == NULL)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	ft_init(&buf);
	ft_create_deq(stack, buf.a, count);
	ft_get_pivot(stack, &pv, count);
	start_sort(buf, pv, count);
	ft_free(&buf);
	return (0);
}
