/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <doyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 20:05:21 by doyun             #+#    #+#             */
/*   Updated: 2021/06/14 16:12:48 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int		*ft_check_dup(int *stack, int count)
{
	int		*temp;

	temp = stack;
	while (--count)
	{
		if (ft_memchr(temp, *temp, count))
		{
			return (NULL);
		}
		temp++;
	}
	return (stack);
}

int		ft_check_ahead(t_deq *deq, int count)
{
	t_node	*temp;
	t_node	*temp_next;

	temp = deq->head;
	if (temp != NULL)
		temp_next = temp->next;
	while (--count > 0)
	{
		if (temp->value < temp_next->value)
		{
			temp = temp_next;
			temp_next = temp_next->next;
		}
		else
			return (0);
	}
	return (1);
}

int		ft_check_atail(t_deq *deq, int count)
{
	t_node	*temp;
	t_node	*temp_prev;	

	temp = deq->tail;	
	if (temp != NULL)
		temp_prev = temp->prev;
	while (--count > 0)
	{
		if (temp->value > temp_prev->value && temp != NULL && temp_prev != NULL)
		{
			temp = temp_prev;
			temp_prev = temp_prev->prev;
		}
		else
			return (0);
	}
	return (1);
}

int		ft_check_bhead(t_deq *deq, int count)
{
	t_node	*temp;
	t_node	*temp_next;

	temp = deq->head;
	if (temp != NULL)
		temp_next = temp->next;
	while (--count && count > 0)
	{
		if (temp->value > temp_next->value)
		{
			temp = temp_next;
			temp_next = temp_next->next;
		}
		else
			return (0);
	}
	return (1);

}

int		ft_check_btail(t_deq *deq, int count)
{
	t_node	*temp;
	t_node	*temp_prev;

	temp = deq->tail;
	if (temp != NULL)
		temp_prev = temp->prev;
	while (--count)
	{
		if (temp->value > temp_prev->value)
		{
			temp = temp_prev;
			temp_prev = temp_prev->prev;
		}
		else
			return (0);
	}
	return (1);
}

void	print_deq(t_deq *a, t_deq *b, t_dsp dsp)
{
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
	printf("disposal ra : %d, pb : %d, rb : %d, pa : %d, rrb: %d\n",dsp.ra, dsp.pb, dsp.rb, dsp.pa, dsp.rrb);
}

int		ft_is_num(char num)
{
	if (num >= '0' && num <= '9')
		return (1);
	else
		return (0);
}

void	dsp_init(t_dsp *dsp)
{
	dsp->ra = 0;
	dsp->pb = 0;
	dsp->rb = 0;
	dsp->pa = 0;
	dsp->rrb = 0;
	dsp->rra = 0;
}

void	ft_get_pivot(int *stack, t_pivot *pv, int count)
{
	if (count > 2)
	{
		ft_quick_sort(stack, 0, count - 1);
		pv->p1 = stack[count/3];
		pv->p2 = stack[2 * count / 3];
	//	printf("pivot : %d %dcount : %d\n",pv->p1, pv->p2, count);
	}
	free(stack);
	stack = NULL;
}

int		ft_get_npivot(int *stack, int count)
{
	int	pivot;

	ft_quick_sort(stack, 0, count);
	pivot = stack[count / 2];
	return (pivot);
}

int		ft_count_arg(char **s, char c)
{
	int			count;
	int			idx;
	int			idx2;

	count = 0;
	idx = 1;
	idx2 = 0;
	while (s[idx] != NULL)
	{
		while (s[idx][idx2] != '\0')
		{
			while (s[idx][idx2] == c)
				idx2++;
			while (s[idx][idx2] != c && s[idx][idx2])
			{
				idx2++;
				if (s[idx][idx2] == c || !(s[idx][idx2]))
					count++;
			}
		}
		idx++;
		idx2 = 0;
	}
	return (count);
}

void		show(int *stack, int count)
{
	int i = 0;
	printf("-------------------\n");
	printf("count : %d\n",count);
	printf("@@@@@@@@@@@stack : ");
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

	if (count <= 0)
		return (NULL);
	idx = -1;
	stack = (int *)ft_calloc(sizeof(int), count);
	while (++idx < count)
	{
		stack[idx] = deq->value;
		deq = deq->next;
	}
	return (stack);
}

int			*put_stack2(t_node *deq, int count)
{
	int		*stack;
	int		idx;

	if (count <= 0)
		return (NULL);
	idx = -1;
	stack = (int *)ft_calloc(sizeof(int), count);
	while (++idx < count)
	{
		stack[idx] = deq->value;
		deq = deq->prev;
	}
	return (stack);
}
