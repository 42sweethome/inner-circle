/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonkang <sonkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:11:46 by sonkang           #+#    #+#             */
/*   Updated: 2021/11/17 11:11:48 by sonkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(void)
{
	char	pwd[1024];

	printf("%s\n", getcwd(pwd, 1024));
}

void	ft_env(char ***envp)
{
	int	idx;

	idx = -1;
	while ((*envp)[++idx])
		printf("%s\n", (*envp)[idx]);
}

void	ft_exit(t_mini *mini)
{
	int	i;

	printf("exit\n");
	if (mini->buf[1])
	{
		i = -1;
		if (mini->buf[1][0] == '-' || mini->buf[1][0] == '+')
			i++;
		while (mini->buf[1][++i])
		{
			if ('0' > mini->buf[1][i] || mini->buf[1][i] > '9')
			{
				printf("minishell: exit: ");
				printf("%s: numeric argument required\n", mini->buf[1]);
				exit (255);
			}
		}
		if (mini->buf[2] && *(mini->buf[2]))
		{
			printf("minishell: exit: too many arguments\n");
			exit(1);
		}
		exit(ft_atoi(mini->buf[1]));
	}
	exit(0);
}
