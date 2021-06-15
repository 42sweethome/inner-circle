/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_sort_case.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <doyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 18:07:39 by doyun             #+#    #+#             */
/*   Updated: 2021/06/11 21:32:36 by sonkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"
void	only3_big_head(t_deq *a)
{
	t_node	*temp;
	t_node	*temp_next;

	temp = a->head->next;
	temp_next = temp->next;
	if (a->head->value > temp_next->value)
	{
		if (temp->value > temp_next->value)
		{
			sa(a);
			rra(a);
		}
		else if (temp->value < temp_next->value)
			ra(a);
	}
	else if (a->head->value < temp_next->value)
		sa(a);
}

void	only3_big_temp(t_deq *a)
{
	t_node	*temp;
	t_node	*temp_next;

	temp = a->head->next;
	temp_next = temp->next;
	if (a->head->value > temp_next->value)
		rra(a);
	else if (a->head->value < temp_next->value)
	{
		if (temp->value > temp_next->value)
		{
			sa(a);
			ra(a);
		}
	}
}

void	noly3_big_head(t_deq *a, t_deq *b)
{
	t_node	*temp;
	t_node	*temp_next;

	temp = a->head->next;
	temp_next = temp->next;
	if (a->head->value > temp_next->value)
	{
		if (temp->value > temp_next->value)
		{
			pb(b, a);
			ra(a);
			pa(a, b);
			sa(a);
			rra(a);
			sa(a);
		}
		else if (temp->value < temp_next->value)
		{
			pb(b, a);
			ra(a);
			pa(a, b);
			sa(a);
			rra(a);
		}
	}
	else if (a->head->value < temp_next->value)
		sa(a);
}

void	noly3_big_temp(t_deq *a, t_deq *b)
{
	t_node	*temp;
	t_node	*temp_next;

	temp = a->head->next;
	temp_next = temp->next;
	if (a->head->value > temp_next->value)
	{
		if (temp->value > temp_next->value)
		{
			pb(b, a);
			sa(a);
			pa(a, b);
			sa(a);
		}
	}
	else if (a->head->value < temp_next->value)
	{
		if (temp->value > temp_next->value)
		{
			pb(b, a);
			sa(a);
			pa(a, b);
		}
	}
}

int		sort_case3(t_deq *a, t_deq *b)
{
	t_node	*temp;
	t_node	*temp_next;

	temp = a->head->next;
	temp_next = temp->next;
	if (temp_next->next == NULL)
	{
		if (a->head->value > temp->value)
			only3_big_head(a);
		else if (a->head->value < temp->value)
			only3_big_temp(a);
		return (0);
	}
//	printf("in case3i\n");
	if (a->head->value > temp->value)
		noly3_big_head(a, b);		
	else if (a->head->value < temp->value)
		noly3_big_temp(a, b);
	return (0);
}

int		sort_case(t_deq *a, t_deq *b, int count)
{
	t_node	*temp;
	int		check;
	
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
		check = sort_case4(a, b);
	else if (count == 5)
		check = sort_case5(a, b);
	else if (count == 6)
		check = sort_case6(a, b);
//	else if (count == 10)
//		check = sort_case10(a, b);
	return (check);
}
