/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 16:38:45 by junghan           #+#    #+#             */
/*   Updated: 2021/05/11 21:50:25 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	push_swap(int ac, char **av)
{
	t_link	stack_a;
	t_link	stack_b;
	t_info	info;
	int		ret;
	int		i;

	if (ac < 2)//???
		;
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
	else if (ret == -1)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	int		err;

	err = push_swap(ac, av);
	if (!err)
	{
		printf("Error\n");
		return (0);
	}
	return (0);
}
