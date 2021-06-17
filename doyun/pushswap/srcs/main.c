/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <doyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 18:01:36 by doyun             #+#    #+#             */
/*   Updated: 2021/06/17 11:26:13 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void		start_sort(t_buf buf, t_pivot pv, int count)
{
	t_dsp	dsp;

	dsp_init(&dsp);
	divide_ra(&buf, pv, count, dsp);
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
	return (0);
}
