#include "minishell.h"

int	add_slash(t_mini *mini, char *path)
{
	int		idx;
	char	*temp;

	idx = -1;
	while (mini->path[++idx])
	{
		temp = ft_strjoin(mini->path[idx], "/");
		if (temp == NULL)
		{
			ft_free(mini->path);
			free(path);
			return (mini->err.malloc);
		}
		free(mini->path[idx]);
		mini->path[idx] = temp;
	}
	return (0);
}

int	get_path(t_mini *mini)
{
	char		*path;
	int			ret;

	ret = ft_getenv(mini, &path, "PATH");
	if (ret == mini->err.malloc)
		return (mini->err.malloc);
	if (ret == 0)
	{
		mini->path = (char **)ft_calloc(1, sizeof(char *));
		mini->path[0] = 0;
		return (1);
	}
	mini->path = ft_split(path, ':');
	ret = add_slash(mini, path);
	if (ret == mini->err.malloc)
		return (mini->err.malloc);
	free(path);
	return (0);
}
