#include "minishell.h"

void	ft_execve(t_mini *mini, char *cmd, char ***envp)
{
	int		pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		redirect_fd(mini->red[0], mini->red_cnt[0], 0);
		if (execve(cmd, mini->buf, *envp) == -1)
			printf("minishell: %s: %s\n", cmd, strerror(errno));
		exit(errno);
	}
	if (pid > 0)
	{
		wait(&status);
		if (WIFEXITED(status)) {
			printf("exited status = %d\n", WEXITSTATUS(status));
			mini->exit_stat = WEXITSTATUS(status);
		}
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
		redirect_fd(mini->red[0], mini->red_cnt[0], 0);
		idx = -1;
		while (mini->path[++idx])
		{
			temp = ft_strjoin(mini->path[idx], cmd);
			if (temp == NULL)
				exit(errno);
			//free(mini->path[idx]);
			mini->path[idx] = temp;
			execve(mini->path[idx], mini->buf, 0);
		}
	//	printf("minishell: %s: %s\n", cmd, strerror(errno));
		cmd_err(cmd, mini->err.cmd, mini);
		exit(errno);
	}
	else if (pid > 0)
	{
		wait(&status);
		if (status == 3072)
			return (mini->err.malloc);
		if (WIFEXITED(status)) {
	//		printf("exited status = %d\n", WEXITSTATUS(status));
			mini->exit_stat = WEXITSTATUS(status);
		}
	}
	else if (pid == -1)
		printf("minishell: %s\n", strerror(errno));
	return (0);
}

int	check_cmd(char *cmd, t_mini *mini, char ***envp) //차 ㅋ 어이없네 ㅋ 이거 중명님 날짜에 무조건 내가 말한다 ㅋㅋ
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
