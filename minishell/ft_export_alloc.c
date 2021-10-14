#include "minishell.h"

int	add_env(t_mini *mini, char **add_arr, char ***envp)
{
	int	idx;
	int	ret;

	idx = add_env_copy(mini, add_arr, envp);
	if (idx == mini->err.malloc)
		return (mini->err.malloc);
	ret = add_env_assign(mini, idx, add_arr);
	if (ret == mini->err.malloc)
	{
		ft_free(add_arr);
		return (mini->err.malloc);
	}
	return (0);
}

int	add_env_alloc(t_mini *mini, char ***envp)
{
	char	**add_arr;
	int		idx;
	int		jdx;
	int		count;

	idx = -1;
	while ((*envp)[++idx])
		;
	jdx = 0;
	count = 0;
	while (mini->buf[++jdx])
		if (*(mini->buf[jdx]) == 0)
			count++;
	add_arr = (char **)ft_calloc(idx + jdx - count + 1, sizeof(char *));
	if (!add_arr)
		return (mini->err.malloc);
	if (add_env(mini, add_arr, envp) == -1)
		return (mini->err.malloc);
	ft_free(*envp);
	*envp = add_arr;
	return (0);
}
