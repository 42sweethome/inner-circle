#include "minishell.h"

char	ft_free(char **new)
{
	size_t		i;

	i = 0;
	while (new[i])
		free(new[i++]);
	free(new);
	return (0);
}

int	al_num_under(int c)
{
	if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || c == '_' ||
		(c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

int	cmd_err(char *cmd, int err_num, t_mini *mini)
{
	if (err_num == mini->err.malloc)
	{
		printf("minishell: malloc error\n");
		return (-1);
	}
	else if (err_num == mini->err.cmd)
		printf("minishell: %s: command not found\n", cmd);
	else if (err_num == mini->err.quo)
		printf("minishell: quotes are not closed\n");
	else if (err_num == mini->err.argv)
		printf("minishell: %s: Hanjungmyung error\n", cmd);
	return (-2);
}
