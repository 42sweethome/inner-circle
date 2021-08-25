/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 14:55:34 by junghan           #+#    #+#             */
/*   Updated: 2021/05/10 17:53:41 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int		apply_comm(t_link *st_a, t_link *st_b, t_info *info, char *comm)
{//설마 이거 나눠야함?
	if (ft_strncmp(comm, "sa", 2) == 0)
		func_sa(st_a, *info);
	else if (ft_strncmp(comm, "sb", 2) == 0)
		func_sb(st_b, *info);
	else if (ft_strncmp(comm, "ss", 2) == 0)
		func_ss(st_a, st_b, info);
	else if (ft_strncmp(comm, "pa", 2) == 0)
		func_pa(st_a, st_b, info);
	else if (ft_strncmp(comm, "pb", 2) == 0)
		func_pb(st_a, st_b, info);
	else if (ft_strncmp(comm, "rra", 3) == 0)
		func_rra(st_a, info);
	else if (ft_strncmp(comm, "rrb", 3) == 0)
		func_rrb(st_b, info);
	else if (ft_strncmp(comm, "rrr", 3) == 0)
		func_rrr(st_a, st_b, info);
	else if (ft_strncmp(comm, "ra", 2) == 0)
		func_ra(st_a, info);
	else if (ft_strncmp(comm, "rb", 2) == 0)
		func_rb(st_b, info);
	else if (ft_strncmp(comm, "rr", 2) == 0)
		func_rr(st_a, st_b, info);
	else
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
			//리스트해제해주기
			free (comm);
			return (-1);
		}
		ret = get_next_line(0, &comm);
		free(comm);
	}
	return (0);
}

void	check_err(int ret)
{
	if (ret == -1)
		write(1, "Error", 5);
	else if (ret == 1)
		write(1, "OK", 2);
	else if (ret == 0)
		write(1, "KO", 2);
}

int		check_set(t_link *st_a, t_link *st_b, t_info *info)
{
	int ret;

	if (st_b->head != NULL)
		return (0);
	ret = check_order(st_a);
	return (ret);
}

int	main(int ac, char **av)
{
	t_link		stack_a;
	t_link		stack_b;
	t_info		info;
	int			ret;
	int			i;

	i = 0;
	init_stack(&stack_a, &stack_b, &info);
	info.check = 1;
	while (av[++i])
	{
		ret = input_int(&stack_a, av[i], ' ', &info.len_a);
		if (!ret)
		{
			check_err(-1);
			return (0);
		}
	}
	ret = apply_list(&stack_a, &stack_b, &info);
	if (ret == -1)
	{
		check_err(ret);
		return (ret);
	}
	ret = check_set(&stack_a, &stack_b, &info);
	check_err(ret);
	//have to free list.
	return (ret);
}
