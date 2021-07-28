/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 16:38:45 by junghan           #+#    #+#             */
/*   Updated: 2021/05/10 17:57:02 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

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
	{
		printf("Error\n");
		return (0);
	}
	return (0);
}
