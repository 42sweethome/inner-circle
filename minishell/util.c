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

int	special_char4(int c)
{
	if (c == ' ' || c == '>' || c == '<' || c == '|' || \
			c == '\0' || c == '$')
		return (0);
	return (1);
}

int	special_char3(int c)
{
	if (c == ' ' || c == '>' || c == '<' || c == '|' || \
			c == '\0')
		return (0);
	return (1);
}

int	special_char2(int c)
{
	if (c == '?' || c == '"' || c == '\''|| c == '>' || c == '<' || \
			c == '|' || c == '$')
		return (0);
	return (1);
}

int	special_char(int c)
{
	if (c == '?' || c == ' ' || c == 0 || c == '>' || c == '<' || \
			c == '|' || c == '"' || c == '\'' || c == '$')
		return (0);
	return (1);
}

int	cmd_err(char *cmd, int err_num, t_mini *mini)
{
	if (err_num == mini->err.malloc || err_num == mini->err.path_malloc || \
		err_num == mini->err.split_malloc)
	{
		printf("minishell: malloc error\n");
		return (err_num);
	}
	else if (err_num == mini->err.cmd)
		printf("minishell: %s: command not found\n", cmd);
	else if (err_num == mini->err.quo)
		printf("minishell: quotes are not closed\n");
	else if (err_num == mini->err.argv)
		printf("minishell: %s: Hanjungmyung error\n", cmd);
	else if (err_num == mini->err.pipe)
		printf("minishell: syntax error near unexpected token `|'\n");
	return (-2);
}
