#include "minishell.h"

void	ft_echo(t_mini *mini)
{
	int idx;
	int option;

	idx = mini->first;
	option = mini->first + 1;
	while (mini->buf[++idx] != 0 && *(mini->buf[idx]) == 0) 
		option++;
	idx = mini->first;
	while(mini->buf[++idx])
	{
		if (idx == option && \
				!ft_strncmp(mini->buf[option], "-n", 3))
			idx++;
		printf("%s", mini->buf[idx]);
		if (mini->buf[idx + 1] != 0 && *(mini->buf[idx]) != 0)
			printf(" ");
		if (mini->buf[idx + 1] == 0 && \
				ft_strncmp(mini->buf[option], "-n", 3))
			printf("\n");
	}	
}

void	ft_pwd(void)//export구현 후 수정
{
	char pwd[1024];

	printf("%s\n", getenv("PWD"));
	printf("%s\n", getcwd(pwd, 1024));
}

void	ft_env(char **envp)
{
	int	idx;

	idx = -1;
	while (envp[++idx])
		printf("%s\n", envp[idx]);
}

void	ft_chdir(t_mini *mini)
{
	int idx;

	idx = mini->first;
	while (mini->buf[++idx] != 0 && *(mini->buf[idx]) == 0)
		;
	if (mini->buf[idx] == 0 || !ft_strncmp("~", mini->buf[idx], 2))//
		chdir(getenv("HOME"));// 클러스터랑 좀 다른 것 같다고함
	else if (&(mini->buf[idx]) != 0 && chdir(mini->buf[idx]) == 0)
		;
	else
		printf("minishell: %s: %s\n", mini->buf[idx], strerror(errno));
}
