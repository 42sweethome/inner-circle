/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_sort_case.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <doyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 18:07:39 by doyun             #+#    #+#             */
/*   Updated: 2021/06/16 18:02:08 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int			sort_case(t_deq *a, t_deq *b, int count)
{
	t_node	*temp;
	int		check;
	int		idx;

	idx = 0;
	check = 0;
	if (a->head != NULL)
		temp = a->head->next;
	if (count == 2)
	{
		if (a->head->value > temp->value)
			sa(a);
	}
	else if (count == 3)
		check = sort_case3(a, b);
	else if (count == 4)
		check = sort_case4(a, b, idx);
	else if (count == 5)
		check = sort_case5(a, b);
	else if (count == 6)
		check = sort_case6(a, b);
	return (check);
}
