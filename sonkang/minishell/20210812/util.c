#include "minishell.h"

int	print_err(char *err_str)
{
	printf("%s\n", err_str);
	return (-2);
}

int	cmd_err(char *cmd)
{
	printf("minishell: %s: command not found\n", cmd);
	return (-2);
}
