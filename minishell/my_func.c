#include "minishell.h"

int    my_func2(char *cmd, t_mini *mini, char ***envp)
{
    if (!ft_strncmp("cd", cmd, 3) || !ft_strncmp("CD", cmd, 3))
		ft_chdir(mini);
    else if (!ft_strncmp("export", cmd, 7) || !ft_strncmp("EXPORT", cmd, 7))
	{
		if (ft_export(mini, envp) == mini->err.malloc)
			return (mini->err.malloc);
	}
	else if (!ft_strncmp("unset", cmd, 6) || !ft_strncmp("UNSET", cmd, 6))
	{
		if (ft_unset(mini, envp) == mini->err.malloc)
			return (mini->err.malloc);
	}
    else
        return (0);
    return (1);
}

void     my_func(char *cmd, t_mini *mini)
{
    if (!ft_strncmp("echo", cmd, 5) || !ft_strncmp("ECHO", cmd, 5))
		ft_echo(mini);
	else if (!ft_strncmp("pwd", cmd, 4) || !ft_strncmp("PWD", cmd, 4)) 
		ft_pwd();
	else if (!ft_strncmp("env", cmd, 4) || !ft_strncmp("ENV", cmd, 4))
		ft_env(mini->envp);
	else if (!ft_strncmp("exit", cmd, 5) || !ft_strncmp("EXIT", cmd, 5))
		ft_exit(mini);
    else
        exit(0);
    exit(1);
}

int 	my_execve(t_mini *mini, char *cmd, char ***envp)
{
    int     ret;
	int		pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		redirect_fd(mini->red[0], mini->red_cnt[0], 0);
        my_func(cmd, mini);
		/*if (my_func(cmd, mini, envp))
			printf("minishell: %s: %s\n", cmd, strerror(errno));*/
		exit(errno);
	}
	if (pid > 0)
	{
		wait(&status);
        ret = my_func2(cmd, mini, envp);
        if (ret == mini->err.malloc)
            return (mini->err.malloc);
        else if (ret == 1)
            return (1);
        else if (!ft_strncmp(cmd, "exit", 5))
            exit (status / 256);
        else if (status == 0 || status == 256)
            return (status / 256);
		else if (WIFEXITED(status)) {
			printf("exited status = %d\n", WEXITSTATUS(status));
			mini->exit_stat = WEXITSTATUS(status);
		}
	}
	else if (pid == -1)
		printf("minishell: %s\n", strerror(errno));
    return (1);
}