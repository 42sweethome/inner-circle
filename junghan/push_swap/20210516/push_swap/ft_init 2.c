/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 16:38:21 by junghan           #+#    #+#             */
/*   Updated: 2021/05/11 16:26:36 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	init_stack(t_link *stack_a, t_link *stack_b, t_info *info)
{
	stack_a->head = 0;
	stack_a->tail = 0;
	stack_a->node = 0;
	stack_b->head = 0;
	stack_b->tail = 0;
	stack_b->node = 0;
	init_info(info);
}

void	init_info(t_info *info)
{
	info->start = 0;
	info->end = 0;
	info->count = 0;
	info->len_a = 0;
	info->len_b = 0;
	info->both = 0;
	info->check = 0;
	info->ra = 0;
	info->rb = 0;
	info->pa = 0;
	info->pb = 0;
}
