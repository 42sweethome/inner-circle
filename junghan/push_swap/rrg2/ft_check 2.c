/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 16:37:36 by junghan           #+#    #+#             */
/*   Updated: 2021/05/13 17:52:54 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	check_err(int ret)
{
	if (ret == -1)
		write(2, "Error\n", 6);
	else if (ret == 1)
		write(1, "OK\n", 3);
	else if (ret == 0)
		write(1, "KO\n", 3);
}

int		check_set(t_link *st_a, t_link *st_b)
{
	int		ret;

	if (st_b->head != NULL)
		return (0);
	ret = check_dup(st_a);
	if (ret == 0)
		return (-1);
	ret = check_order(st_a);
	return (ret);
}

int		check_dup(t_link *st_a)
{
	t_circle	*tmp;
	t_circle	*cmp;

	tmp = st_a->head;
	while (tmp)
	{
		cmp = tmp->next;
		while (cmp)
		{
			if (tmp->value == cmp->value)
				return (0);
			cmp = cmp->next;
		}
		tmp = tmp->next;
	}
	return (1);
}

int		check_order(t_link *st_a)
{
	t_circle	*tmp;

	tmp = st_a->head;
	if (!tmp)
		return (1);
	while (tmp->next)
	{
		if (tmp->value >= tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int		check_sort(t_link *st_a, t_link *st_b, t_info *info)
{
	int			ret;

	ret = check_dup(st_a);
	if (ret == 0)
		return (-1);
	ret = check_order(st_a);
	if (ret == 1)
		return (1);
	if (info->len_a < 2)
		return (1);
	else if (info->len_a <= 5)
	{
		ret = exit_easy(st_a, st_b, info->len_a, info);
		if (ret == 1)
			return (1);
	}
	return (0);
}
