#include "minishell.h"

int    my_func2(char *cmd, t_mini *mini, char ***envp)
{
    if (!ft_strncmp("cd", cmd, 3))
		ft_chdir(mini);
    else if (!ft_strncmp("export", cmd, 7) && mini->upper == 0) //???? 키값 검
	{
		if (ft_export(mini, envp) == mini->err.malloc)
			return (mini->err.malloc);
	}
	else if (!ft_strncmp("unset", cmd, 6) && mini->upper == 0)
	{
		if (ft_unset(mini, envp) == mini->err.malloc)
			return (mini->err.malloc);
	}
    else
        return (1);
    return (0);
}

void     my_func(char *cmd, t_mini *mini)
{
    if (!ft_strncmp("echo", cmd, 5) || !ft_strncmp("ECHO", cmd, 5)) //????
		ft_echo(mini);
	else if (!ft_strncmp("pwd", cmd, 4) || !ft_strncmp("PWD", cmd, 4)) 
		ft_pwd();
	else if (!ft_strncmp("env", cmd, 4) || !ft_strncmp("ENV", cmd, 4))
		ft_env(&mini->envp);
	else if (!ft_strncmp("exit", cmd, 5) && mini->upper == 0)
		ft_exit(mini);
    else
		exit(1);
    exit(0);
}

char	*upper_case(t_mini *mini, char *cmd)
{
	char	*tmp;
	int		i;

	if (!cmd)
		return (0);
	tmp = (char *)ft_calloc(ft_strlen(cmd) + 1, sizeof(char));
	i = -1;
	while (cmd[++i])
	{
		if (cmd[i] >= 'A' && cmd[i] <= 'Z')
		{
			tmp[i] = cmd[i] + 32;
			mini->upper = 1;
		}
		else
			tmp[i] = cmd[i];
	}
	return (tmp);
}

int	check_digit(char *arg)
{
	int i;

	i = -1;
	if (arg[0] == '-' || arg[0] == '+')
		i++;
	while (arg[++i])
		if (arg[i] < '0' || arg[i] > '9')
			return (0);
	return (1);
}

int 	my_execve(t_mini *mini, char *cmd, char ***envp)
{
	char	*cmd_tmp;
    int     ret;
	int		pid;
	int		status;

	cmd_tmp = upper_case(mini, cmd);
	pid = fork();
	if (pid == 0)
	{
		if (mini->redirect)
			redirect_fd(mini->red[0], mini->red_cnt[0], 0);
        my_func(cmd_tmp, mini);
	}
	if (pid > 0)
	{
		wait(&status);
        ret = my_func2(cmd_tmp, mini, envp);
		free(cmd_tmp);
        if (ret == mini->err.malloc)
            return (mini->err.malloc);
        else if (ret == 0) //func2 export unset cd
            return (0);
		mini->exit_stat = WEXITSTATUS(status);//
        if (!ft_strncmp(cmd, "exit", 5)) //exit
		{
			if (!mini->buf[1])
				exit(0);
			else if (!(check_digit(mini->buf[1]) && mini->buf[2]))
				exit (status / 256);
		}
        else if (status == 0 || status == 256) //func1 echo pwd env exit
            return (status / 256);
		else if (WEXITSTATUS(status) == 2)
		{
			printf("minishell: %s\n", strerror(WEXITSTATUS(status)));
			mini->exit_stat = 1;
		}
	}
	else if (pid == -1)
		printf("minishell: %s\n", strerror(errno));
    return (0);
}