/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 16:38:45 by junghan           #+#    #+#             */
/*   Updated: 2021/04/29 17:50:59 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	init_stack(t_link *stack_a, t_link *stack_b, t_info *info)
{
	stack_a->head = 0;//init함수로 한꺼번에 초기화
	stack_a->tail = 0;
	stack_a->node = 0;
	stack_b->head = 0;
	stack_b->tail = 0;
	stack_b->node = 0;
	init_info(info);
}

void	init_info(t_info *info)
{
	info->len_a = 0;
	info->len_b = 0;
	info->ra = 0;
	info->rb = 0;
	info->pa = 0;
	info->pb = 0;
}

int	push_swap(int ac, char **av)
{
	t_link	stack_a;
	t_link	stack_b;
	t_circle *tmp;
	t_circle *tmp_b;
	t_info	info;
	int	ret;
	int	i;

	i = 0;
	init_stack(&stack_a, &stack_b, &info);
	while (av[++i])
	{
		ret = input_int(&stack_a, av[i], ' ', &info.len_a);
		if (!ret)
			return (0);
	}
	ret = check_sort(&stack_a, &info);
	if (ret == 0)
		sort_st(&stack_a, &stack_b, &info);
	tmp = stack_a.head;
	tmp_b = stack_b.head;
	while (tmp)
	{
		printf("a = %d\n", tmp->value);
		tmp = tmp->next;
	}
	while (tmp_b)
	{
		printf("b = %d\n", tmp_b->value);
		tmp_b = tmp_b->next;
	}
	return(1);
}

int	main(int ac, char **av)
{
	int err;

	err = push_swap(ac, av);
	if (!err)// ko??
		return (-1);
	return (0);
}
