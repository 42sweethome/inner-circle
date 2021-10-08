#include "minishell.h"

int    my_func2(char *cmd, t_mini *mini, char ***envp)
{
    if (!ft_strncmp("cd", cmd, 3) || !ft_strncmp("CD", cmd, 3))
		ft_chdir(mini);
    else if (!ft_strncmp("export", cmd, 7) || !ft_strncmp("EXPORT", cmd, 7)) //???? 키값 검ㅅ
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
		ft_env(mini->envp);
	else if (!ft_strncmp("exit", cmd, 5) || !ft_strncmp("EXIT", cmd, 5))
		ft_exit(mini);
    else
		exit(1);
    exit(0);
}

int 	my_execve(t_mini *mini, char *cmd, char ***envp)
{
    int     ret;
	int		pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		if (mini->red)
			redirect_fd(mini->red[0], mini->red_cnt[0], 0);
        my_func(cmd, mini);
	}
	if (pid > 0)
	{
		wait(&status);
//		printf("ret %d\n", status);
        ret = my_func2(cmd, mini, envp);
//		printf("ret %d exits %d\n", ret, mini->exit_stat);
        if (ret == mini->err.malloc)
            return (mini->err.malloc);
        else if (ret == 0) //func2 export unset cd
            return (0);
		mini->exit_stat = WEXITSTATUS(status);//
        if (!ft_strncmp(cmd, "exit", 5)) //exit
            exit (status / 256);
        else if (status == 0 || status == 256) //func1 echo pwd env exit
            return (status / 256);//printf("myexecve exited status = %d\n", WEXITSTATUS(status));
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