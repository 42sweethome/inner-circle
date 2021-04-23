/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:01:00 by junghan           #+#    #+#             */
/*   Updated: 2021/04/22 17:12:00 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	func_sa(int *st_a, int len)
{
	int	tmp;
	if (len < 2)
		return ;
	tmp = st_a[0];
	st_a[0] = st_a[1];
	st_a[1] = tmp;
}

void	func_sb(int *st_b, int len)
{
	int	tmp;

	if (len < 2)
		return ;
	tmp = st_b[0];
	st_b[0] = st_b[1];
	st_b[1] = tmp;
}

void	func_ss(int *st_a, int *st_b)
{
	func_sa(st_a);
	func_sb(st_b);
}
