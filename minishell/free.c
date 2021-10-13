#include "minishell.h"

int	main_free(t_mini *mini, char *str, int ret)
{
	if (mini->redirect)
	{
		ft_struct_free(mini, mini->red);
		free(mini->red_cnt);
	}
	if (ret == mini->err.path_malloc || ret == mini->err.only_space)
	{
		ft_free(mini->path);
		free(str);
		return (mini->err.malloc);
	}
	ft_free(mini->path);
	ft_free(mini->buf);
	free(str);
	if (ret == mini->err.malloc || ret == mini->err.cmd)
		return (ret);
	return (0);
}

char	ft_free(char **new)
{
	size_t		i;

	i = 0;
	while (new[i])
		free(new[i++]);
	free(new);
	return (0);
}

char	ft_int_free(int **fd, int n, int *pid)
{
	int		i;

	i = -1;
	while (++i < n)
		free(fd[i]);
	free(fd);
	free(pid);
	return (0);
}

char	ft_struct_free(t_mini *mini, t_redir **new)
{
	int	i;
	int	j;

	i = -1;
	while (++i < mini->pipe + 1)
	{
		j = -1;
		while (++j < mini->red_cnt[i])
		{
			free(new[i][j].file);
			free(new[i][j].redir);
		}
		free(new[i]);
	}
	free(new);
	return (0);
}
