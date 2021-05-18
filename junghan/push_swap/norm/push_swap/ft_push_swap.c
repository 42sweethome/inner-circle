/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 16:38:45 by junghan           #+#    #+#             */
/*   Updated: 2021/05/18 15:54:32 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	push_swap(char **av)
{
	t_link	stack_a;
	t_link	stack_b;
	t_info	info;
	int		ret;
	int		i;

	i = 0;
	init_stack(&stack_a, &stack_b, &info);
	while (av[++i])
	{
		ret = input_int(&stack_a, av[i], ' ', &info.len_a);
		if (ret == -1)
			break ;
	}
	if (ret != -1)
		ret = check_sort(&stack_a, &stack_b, &info);
	if (ret == 0)
		ret = sort_st(&stack_a, &stack_b, &info);
	lstclear(&stack_a.head, &stack_a.tail);
	lstclear(&stack_b.head, &stack_b.tail);
	return (ret);
}

int	main(int ac, char **av)
{
	int		err;

	if (ac >= 2)
		err = push_swap(av);
	else
		return (0);
	if (err == -1)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (0);
}
