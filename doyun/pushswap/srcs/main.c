/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <doyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 18:01:36 by doyun             #+#    #+#             */
/*   Updated: 2021/06/16 18:01:37 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void		start_sort(t_deq a, t_deq b, t_pivot pv, int count)
{
	t_dsp	dsp;

	dsp_init(&dsp);
	divide_ra(&a, &b, pv, count, dsp);
}

int			main(int argc, char **argv)
{
	int		count;
	int		*stack;
	t_pivot pv;
	t_deq	a;
	t_deq	b;

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
	ft_init(&a, &b);
	ft_create_deq(stack, &a, count);
	ft_get_pivot(stack, &pv, count);
	start_sort(a, b, pv, count);
	return (0);
}
