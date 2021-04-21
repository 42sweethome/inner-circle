/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 16:38:45 by junghan           #+#    #+#             */
/*   Updated: 2021/04/21 19:28:35 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void push_swap(int ac, char **av)
{
	int	*stack_a;
	int	*stack_b;
	int	i;
	int	len;

	i = 0;
	len = 0;
	stack_a = 0;
	stack_b = 0;
	while (av[++i])
	{
		stack_a = input_int(stack_a, &len, av[i], ' ');
	}
	i = -1;
}

int	main(int ac, char **av)
{
	push_swap(ac, av);
	return (0);
}
