#include "minishell.h"

int	get_rm_arr_cnt(t_mini *mini, char ***envp)
{
	int	count;
	int	idx;
	int	jdx;

	count = -1;
	while ((*envp)[++count])
		;
	idx = -1;
	while ((*envp)[++idx])
	{
		jdx = 0;
		while (mini->buf[++jdx])
		{	
			if (!ft_strncmp(mini->buf[jdx], (*envp)[idx], \
						ft_strlen(mini->buf[jdx])))
				count--;
		}
	}
	return (count);
}

int	arrange_env(t_mini *mini, char ***envp, char **rm_arr, int flag)
{
	int	idx;
	int	jdx;

	idx = -1;
	while ((*envp)[++idx])
	{
		jdx = 0;
		while (mini->buf[++jdx])
		{
			if (!ft_strncmp(mini->buf[jdx], (*envp)[idx], \
						ft_strlen(mini->buf[jdx])))
			{
				flag++;
				break ;
			}
		}
		if (mini->buf[jdx] == 0)
		{
			rm_arr[idx - flag] = ft_strdup((*envp)[idx]);
			if (rm_arr[idx - flag] == 0)
				return (mini->err.malloc);
		}
	}
	return (0);
}

int	rm_env(t_mini *mini, char ***envp)
{
	char	**rm_arr;
	int		flag;
	int		count;

	count = get_rm_arr_cnt(mini, envp);
	rm_arr = (char **)ft_calloc(count + 1, sizeof(char *));
	if (!rm_arr)
		return (mini->err.malloc);
	flag = 0;
	if (arrange_env(mini, envp, rm_arr, flag) == -1)
	{
		ft_free(rm_arr);
		return (mini->err.malloc);
	}
	ft_free(*envp);
	*envp = rm_arr;
	return (0);
}

int	ft_unset(t_mini *mini, char ***envp)
{
	int	idx;

	idx = mini->first;
	if (mini->buf[++idx] == 0)
		return (0);
	else
		if (rm_env(mini, envp) == mini->err.malloc)
			return (mini->err.malloc);
	mini->exit_stat = 0;
	return (0);
}
