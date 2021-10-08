#include "minishell.h"

void	ft_execve(t_mini *mini, char *cmd, char ***envp)
{
	int		pid;
	int		status;

	
	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);// SIG_ING 시그널 무시
		if (mini->red)
			redirect_fd(mini->red[0], mini->red_cnt[0], 0);
		if (execve(cmd, mini->buf, *envp) == -1)
			printf("minishell: %s: %s\n", cmd, strerror(errno));
		exit(errno);
	}
	if (pid > 0)
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);// SIG_ING 시그널 무시
		wait(&status);
		mini->exit_stat = WEXITSTATUS(status);
		if (status == 2)
			printf("^C\n");
		else if (status == 3)
			printf("^\\Quit: %d\n", status);
		else if (WEXITSTATUS(status) == 2) //????
				printf("minishell: %s\n", strerror(errno));
		else if (WEXITSTATUS(status) != 2 && WEXITSTATUS(status) != 0)
				printf("minishell: bash error\n");
	}
	else if (pid == -1)
		printf("minishell: %s\n", strerror(errno));
}

int	check_path(t_mini *mini, char *cmd)
{
	char	*temp;
	int		pid;
	int		status;
	int		idx;

	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);// SIG_ING 시그널 무시
		if (mini->red)
			redirect_fd(mini->red[0], mini->red_cnt[0], 0);
		idx = -1;
		if (cmd == 0)
			exit(0);
		while (mini->path[++idx])
		{
			temp = ft_strjoin(mini->path[idx], cmd);
			if (temp == NULL)
				exit(errno);
			//free(mini->path[idx]);
			mini->path[idx] = temp;
			execve(mini->path[idx], mini->buf, 0);
		}
		exit(45);
	}
	else if (pid > 0)
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);// SIG_ING 시그널 무시
		wait(&status);
		//signal(SIGINT, sig_handler);
		//signal(SIGQUIT, SIG_IGN);
		mini->exit_stat = WEXITSTATUS(status);
		if (status == 3072)
			return (mini->err.malloc);
		else if (status == 2)
			printf("^C\n");
		else if (status == 3)
			printf("^\\Quit: %d\n", status);
		else if (WEXITSTATUS(status) == 45) //????
			cmd_err(cmd, mini->err.cmd, mini);
		else if (WEXITSTATUS(status) != 2 && WEXITSTATUS(status) != 0)
			printf("minishell: bash error\n");
	}
	else if (pid == -1)
		printf("minishell: %s\n", strerror(errno));
	return (0);
}

int	check_cmd(char *cmd, t_mini *mini, char ***envp)
{
	int		ret;
	//redirect_fd(mini->red[0], mini->red_cnt[0], 0);
	ret = my_execve(mini, cmd, envp);
	if (ret == mini->err.malloc)
		return (mini->err.malloc);
	else if (ret == 1)
		return (0);
	else if (ft_strchr(cmd, '/') != 0)
		ft_execve(mini, cmd, envp);	
	else
		return (check_path(mini, cmd));
	return (0);
}
