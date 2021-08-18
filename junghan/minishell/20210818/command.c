#include "minishell.h"

void	ft_echo(t_mini *mini)
{
	int idx;

	idx = 0;
	while(mini->buf[++idx])
	{
		if (idx == 1 && !ft_strncmp(mini->buf[1], "-n", 3))
			idx++;
		printf("%s", mini->buf[idx]);
		if (mini->buf[idx + 1] != 0)
			printf(" ");
		if (mini->buf[idx + 1] == 0 && ft_strncmp(mini->buf[1], "-n", 3))
			printf("\n");
	}	
}

void	ft_pwd(void)
{
	printf("%s\n",getenv("PWD"));
}

void	ft_env(char **envp)
{
	int	idx;

	idx = -1;
	while (envp[++idx])
		printf("%s\n", envp[idx]);
}
