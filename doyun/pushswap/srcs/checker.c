/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <doyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 19:18:32 by doyun             #+#    #+#             */
/*   Updated: 2021/06/10 22:09:12 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int		apply_stdin(t_deq *a, t_deq *b, char *line)
{
	if (ft_strncmp(line, "sa", 2))
		sa(a);
	else if (ft_strncmp(line, "sb", 2))
		sb(b);
	else if (ft_strncmp(line, "ss", 2))
		ss(a, b);
	else if (ft_strncmp(line, "pa", 2))
		pa(a, b);
	else if (ft_strncmp(line, "pb", 2))
		pb(b, a);
	else if (ft_strncmp(line, "ra", 2))
		ra(a);
	else if (ft_strncmp(line, "rb", 2))
		rb(b);
	else if (ft_strncmp(line, "rr", 2))
		rr(a, b);
	else if (ft_strncmp(line, "rra", 3))
		rra(a);
	else if (ft_strncmp(line, "rrb", 3))
		rrb(b);
	else if (ft_strncmp(line, "rrr", 3))
		rrr(a, b);
	else
		return (1);
	return (0);
}

int		check_sort(t_deq *a, t_deq *b)
{
	t_node *temp;
	t_node *temp_next;

	temp = a->head;
	temp_next = a->head->next;
	while (temp_next != NULL)
	{
		if (temp->value > temp_next->value)
			return (1);
		temp = temp_next;
		temp_next = temp_next->next;
	}
	if (b != NULL)
		return (1);
	return (0);
}

int		main(int argc, char **argv)
{
	if (argc == 0)
		return (-1);
	int count;
	int	*stack;
	t_deq	a;
	t_deq	b;
	char	*line;

	count = ft_count_arg(argv, ' ');
	stack = ft_get_sortstack(argc, argv, count);
	if (stack == NULL)
	{
		write(1, "ERROR\n", 6);
		return(0);
	}
	ft_init(&a, &b);
	ft_create_deq(stack, &a, count);
	while (get_next_line(0, &line) > 0)
	{
		if (apply_stdin(&a, &b, line))
		{
			write(1, "ERROR\n", 6);
			return (0);
		}
	}
	if (check_sort(&a, &b))
	{
		write(1, "KO\n", 3);
		return (0);
	}
	write(1, "OK\n", 3);
	//	ft_get_pivot(stack, &pv, count);
	//	divide_ra(&a, &b, pv, count);
	//	dsp_init(&dsp);
	//	print_deq(&a, &b, dsp);
	return (0);
}
