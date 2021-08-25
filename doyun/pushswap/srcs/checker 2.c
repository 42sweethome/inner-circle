/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <doyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 19:18:32 by doyun             #+#    #+#             */
/*   Updated: 2021/06/22 14:21:58 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int			apply_stdin(t_deq *a, t_deq *b, char *line)
{
	if (ft_strncmp(line, "sa", 2))
		csa(a);
	else if (ft_strncmp(line, "sb", 2))
		csb(b);
	else if (ft_strncmp(line, "ss", 2))
		css(a, b);
	else if (ft_strncmp(line, "pa", 2))
		cpa(a, b);
	else if (ft_strncmp(line, "pb", 2))
		cpb(b, a);
	else if (ft_strncmp(line, "ra", 2))
		cra(a);
	else if (ft_strncmp(line, "rb", 2))
		crb(b);
	else if (ft_strncmp(line, "rra", 3))
		crra(a);
	else if (ft_strncmp(line, "rrb", 3))
		crrb(b);
	else if (ft_strncmp(line, "rrr", 3))
		crrr(a, b);
	else if (ft_strncmp(line, "rr", 2))
		crr(a, b);
	else
		return (1);
	return (0);
}

int			check_sort(t_deq *a, t_deq *b)
{
	t_node	*temp;
	t_node	*temp_next;

	temp = a->head;
	temp_next = a->head->next;
	while (temp_next != NULL)
	{
		if (temp->value > temp_next->value)
			return (1);
		temp = temp_next;
		temp_next = temp_next->next;
	}
	if (b->head != NULL)
		return (1);
	return (0);
}

void		check_stdin(t_deq *a, t_deq *b)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		if (apply_stdin(a, b, line))
		{
			write(2, "Error\n", 6);
			free(line);
			return ;
		}
		free(line);
	}
	if (check_sort(a, b))
	{
		write(1, "KO\n", 3);
		free(line);
		return ;
	}
	free(line);
	write(1, "OK\n", 3);
}

int			main(int argc, char **argv)
{
	int		count;
	int		*stack;
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
	check_stdin(buf.a, buf.b);
	checker_free(&buf);
	return (0);
}
