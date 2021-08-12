#include "minishell.h"

int	check_cmd(char *cmd)
{
	if (!ft_strncmp("echo", cmd, 5) || !ft_strncmp("ECHO", cmd, 5))
		;
	else if (!ft_strncmp("cd", cmd, 3) || !ft_strncmp("CD", cmd, 3))
		;
	else if (!ft_strncmp("pwd", cmd, 4) || !ft_strncmp("PWD", cmd, 4)) 
		;
	else if (!ft_strncmp("export", cmd, 7) || !ft_strncmp("EXPORT", cmd, 7))
		;
	else if (!ft_strncmp("unset", cmd, 6) || !ft_strncmp("UNSET", cmd, 6))
		;
	else if (!ft_strncmp("env", cmd, 4) || !ft_strncmp("ENV", cmd, 4))
		;
	else if (!ft_strncmp("exit", cmd, 5) || !ft_strncmp("EXIT", cmd, 5))
		;
	else
		return (-2);
	return (0);
}
