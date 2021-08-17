#include "minishell.h"

int	al_num_under(int c)
{
	if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || c == '_' ||
		(c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

int	print_err(char *err_str)
{
	printf("%s\n", err_str);
	return (-2);
}

int	cmd_err(char *cmd, int err_num)
{
	if (err_num == -2)
		printf("minishell: %s: command not found\n", cmd);
	else if (err_num == -3)
		printf("minishell: %s: No such file or directory\n", cmd);
	return (-2);
}
