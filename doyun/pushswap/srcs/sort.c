/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <doyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:37:19 by doyun             #+#    #+#             */
/*   Updated: 2021/06/03 18:04:56 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void		show(int *stack, int count)
{
	int i = 0;

	printf("@@@@@@@@@@@@@stack : ");
	while (i < count)
	{
		printf("%d ",stack[i]);
		i++;
	}
	printf("\n");
}

int			*put_stack(t_node *deq, int count)
{
	int		*stack;
	int		idx;

	idx = -1;
	stack = (int *)ft_calloc(sizeof(int), count);
	while (deq != NULL)
	{
		stack[++idx] = deq->value;
		deq = deq->next;
	}
	return (stack);
}

void		last_sort_ra(t_deq *deq, int count)
{
	t_node	*temp;
	int		i;

	temp = deq->head->next;
	i = 0;
	while (i++ < count)
		rra(deq);
	if (count > 1)
	{
		if (deq->head->value > temp->value)
		{
			sa(deq);
		}
	}
}

void		last_sort_pb(t_deq *a, t_deq *b, int count)
{
	t_node *temp;

	temp = b->head->next;
	if (b->head->value < temp->value)
		sb(b);
	while (count--)
		pa(a, b);	
}

void		divide_ra(t_deq *a, t_deq *b, t_pivot pv, int count)
{
	t_dsp dsp;
	int i;
	int	*stack;

	i = 0;
	dsp.ra = 0;
	dsp.rb = 0;
	dsp.pb = 0;
	while(i < count)
	{
		if (a->head->value >= pv.p2)
		{
			ra(a);
			dsp.ra++;
		}
		else if (a->head->value <= pv.p1)
		{
			pb(b, a);
			rb(b);
			dsp.rb++;
		}
		else
		{
			pb(b, a);
			dsp.pb++;
		}
		i++;	
		printf("divide a : ");
		t_node *temp = a->head;
		while (temp != NULL)
		{
			printf("%d ",temp->value);
			temp = temp->next;
		}
		temp = b->head;
		printf("divide b : ");
		while (temp != NULL)
		{
			printf("%d ",temp->value);
			temp = temp->next;
		}
		printf("\n");
		printf("disposal : %d %d %d\n",dsp.ra, dsp.pb, dsp.rb);
	}
	//if (dsp.ra < 3)
	//	return;
	//	t_get_pivot(ft_quick_sort(
	stack = put_stack(a->head, dsp.ra);
	show(stack, dsp.ra);//
	if (dsp.ra <= 2)
	{
		last_sort_ra(a, dsp.ra);
		ft_get_pivot(stack, &pv, dsp.pb);
		divide_pb(a, b, pv, dsp.pb);
		//	divide_rb();
		return ;
	}
	ft_get_pivot(stack, &pv, dsp.ra);
	divide_ra(a, b, pv, dsp.ra);
}

void	divide_pb(t_deq *a, t_deq *b, t_pivot pv, int count)
{
	printf("start pb\n");
	t_dsp dsp;
	int i;

	i = 0;
	dsp.ra = 0;
	dsp.rb = 0;
	dsp.pb = 0;
	dsp.pb = 0;
	if (count <= 2)
	{
		return(last_sort_pb(a, b, dsp.pb));
	}
	while(i < count)
	{
		if (b->head->value >= pv.p2)
		{
			pa(a, b);
			ra(a);
			dsp.ra++;
		}
		else if (a->head->value <= pv.p1)
		{
			rb(b);
			dsp.rb++;
		}
		else
		{
			pa(a, b);
			dsp.pa++;
		}
		while (dsp.pa--)
		{
			pb(b, a);
			dsp.pb++;
		}
		i++;
		printf("divide a : ");
		t_node *temp = a->head;
		while (temp != NULL)
		{
			printf("%d ",temp->value);
			temp = temp->next;
		}
		temp = b->head;
		printf("divide b : ");
		while (temp != NULL)
		{
			printf("%d ",temp->value);
			temp = temp->next;
		}
		printf("\n");
		printf("disposal : %d %d %d\n",dsp.ra, dsp.pb, dsp.rb);
	}
	printf("%d %d %d %d %d",pv.p1, pv.p2, dsp.ra, dsp.pb ,dsp.rb);
	divide_ra(a, b, pv, dsp.ra);
}
