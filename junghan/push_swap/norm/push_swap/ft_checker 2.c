/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 14:55:34 by junghan           #+#    #+#             */
/*   Updated: 2021/05/16 16:33:58 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int		apply_comm2(t_link *st_a, t_link *st_b, t_info *info, char *comm)
{
	int		ret;

	ret = -1;
	if (ft_strncmp(comm, "sb", 2) == 0)
		ret = func_sb(st_b, *info);
	else if (ft_strncmp(comm, "ss", 2) == 0)
		ret = func_ss(st_a, st_b, info);
	else if (ft_strncmp(comm, "rrb", 3) == 0)
		ret = func_rrb(st_b, info);
	else if (ft_strncmp(comm, "rrr", 3) == 0)
		ret = func_rrr(st_a, st_b, info);
	else if (ft_strncmp(comm, "rb", 2) == 0)
		ret = func_rb(st_b, info);
	else if (ft_strncmp(comm, "rr", 3) == 0)
		ret = func_rr(st_a, st_b, info);
	else if (ft_strncmp(comm, "pa", 2) == 0)
		ret = func_pa(st_a, st_b, info);
	else if (ft_strncmp(comm, "pb", 2) == 0)
		ret = func_pb(st_a, st_b, info);
	else
		return (0);
	return (ret);
}

int		apply_comm(t_link *st_a, t_link *st_b, t_info *info, char *comm)
{
	int		ret;

	if (comm == NULL)
		return (1);
	ret = -1;
	if (ft_strncmp(comm, "sa", 2) == 0)
		ret = func_sa(st_a, *info);
	else if (ft_strncmp(comm, "ss", 2) == 0)
		ret = func_ss(st_a, st_b, info);
	else if (ft_strncmp(comm, "rra", 3) == 0)
		ret = func_rra(st_a, info);
	else if (ft_strncmp(comm, "rrr", 3) == 0)
		ret = func_rrr(st_a, st_b, info);
	else if (ft_strncmp(comm, "ra", 2) == 0)
		ret = func_ra(st_a, info);
	else if (ft_strncmp(comm, "rr", 3) == 0)
		ret = func_rr(st_a, st_b, info);
	else
		ret = apply_comm2(st_a, st_b, info, comm);
	if (ret == 0)
		return (0);
	return (1);
}

int		apply_list(t_link *st_a, t_link *st_b, t_info *info)
{
	int		ret;
	int		err;
	char	*comm;

	ret = get_next_line(0, &comm);
	while (ret > 0)
	{
		err = apply_comm(st_a, st_b, info, comm);
		if (!err)
		{
			free(comm);
			return (-1);
		}
		free(comm);
		ret = get_next_line(0, &comm);
	}
	free(comm);
	comm = 0;
	return (0);
}

int		main(int ac, char **av)
{
	t_link	stack_a;
	t_link	stack_b;
	t_info	info;
	int		ret;
	int		i;

	if (ac < 2)
		return (0);
	i = 0;
	init_stack(&stack_a, &stack_b, &info);
	info.check = 1;
	while (av[++i])
	{
		ret = input_int(&stack_a, av[i], ' ', &info.len_a);
		if (ret == -1)
			break ;
	}
	if (ret != -1)
		ret = apply_list(&stack_a, &stack_b, &info);
	if (ret != -1)
		ret = check_set(&stack_a, &stack_b);
	lstclear(&stack_a.head, &stack_a.tail);
	lstclear(&stack_b.head, &stack_b.tail);
	check_err(ret);
	return (ret);
}
