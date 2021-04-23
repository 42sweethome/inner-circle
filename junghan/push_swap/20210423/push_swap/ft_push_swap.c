/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 16:38:45 by junghan           #+#    #+#             */
/*   Updated: 2021/04/23 16:02:08 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	push_swap(int ac, char **av)
{
//	t_circle *stack_a;//헤드역할을 함 테일도 만들어줘야함
	t_link	stack_a;
	t_circle *tmp;
	int	*stack_b;
	int	err;
	int	i;
	int	len;

	i = 0;
	len = 0;
	stack_a.head = 0;//init함수로 한꺼번에 초기화
	stack_a.tail = 0;
	stack_a.node = 0;
	stack_b = 0;
	while (av[++i])
	{
		err = input_int(&stack_a, av[i], ' ');
		if (!err)
			return(0);
	}
//	quick_sort(stack_a, stack_b, 0, len - 1);
	tmp = stack_a.head;
	while (tmp)
	{
		printf("%d\n", tmp->value);
		tmp = tmp->next;
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
