/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonkang <sonkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:11:28 by sonkang           #+#    #+#             */
/*   Updated: 2021/11/17 11:11:31 by sonkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_status(t_mini *mini, char *cmd, int status)
{
	if (status == 2)
		printf("^C\n");
	else if (status == 3)
		printf("^\\Quit: %d\n", status);
	else if (WEXITSTATUS(status) == 127)
		cmd_err(cmd, mini->err.cmd, mini);
}

void	ft_execve(t_mini *mini, char *cmd, char ***envp)
{
	int		pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		if (mini->redirect)
			redirect_fd(mini->red[0], mini->red_cnt[0], 0);
		execve(cmd, mini->buf, *envp);
		exit(127);
	}
	if (pid > 0)
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
		wait(&status);
		mini->exit_stat = WEXITSTATUS(status);
		handle_status(mini, cmd, status);
	}
	else if (pid == -1)
		printf("minishell: %s\n", strerror(errno));
}

int	check_path_child(t_mini *mini, char *cmd)
{
	char	*temp;
	int		idx;

	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	if (mini->redirect)
		redirect_fd(mini->red[0], mini->red_cnt[0], 0);
	idx = -1;
	if (cmd == 0)
		exit(0);
	while (mini->path[++idx])
	{
		temp = ft_strjoin(mini->path[idx], cmd);
		if (temp == NULL)
			exit(errno);
		mini->path[idx] = temp;
		execve(mini->path[idx], mini->buf, 0);
	}
	exit(127);
}

int	check_path(t_mini *mini, char *cmd)
{
	int		pid;
	int		status;

	pid = fork();
	if (pid == 0)
		check_path_child(mini, cmd);
	if (pid > 0)
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
		wait(&status);
		if (status < 128 && status != 0)
			mini->exit_stat = status + 128;
		else
			mini->exit_stat = WEXITSTATUS(status);
		if (status == 3072)
			return (mini->err.malloc);
		else
			handle_status(mini, cmd, status);
	}
	else if (pid == -1)
		printf("minishell: %s\n", strerror(errno));
	return (0);
}

int	check_cmd(char *cmd, t_mini *mini, char ***envp)
{
	int		ret;

	ret = my_execve(mini, cmd, envp);
	if (ret == mini->err.malloc)
		return (mini->err.malloc);
	else if (ret == 0)
		return (0);
	else if (ft_strchr(cmd, '/') != 0)
		ft_execve(mini, cmd, envp);
	else
		return (check_path(mini, cmd));
	return (0);
}
