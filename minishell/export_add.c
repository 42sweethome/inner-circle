#include "minishell.h"

int	add_arr_cmp(t_mini *mini, char **add_arr, int offset, int idx)
{
	int	jdx;

	jdx = -1;
	while (add_arr[++jdx])
	{
		if (!ft_strncmp(mini->buf[offset], add_arr[jdx], idx))
		{
			add_arr[jdx] = ft_strdup(mini->buf[offset]);
			if (add_arr[jdx] == 0)
			{
				ft_free(add_arr);
				return (mini->err.malloc);
			}
			return (1);
		}
	}
	return (0);
}

int	cmp_key(t_mini *mini, char **add_arr, int offset)
{
	int	idx;
	int	ret;

	idx = -1;
	while (mini->buf[offset][++idx])
		if (mini->buf[offset][idx] == '=')
			break ;
	if (!mini->buf[offset][idx])
	{
		mini->exit_stat = 1;
		return (1);
	}
	mini->exit_stat = 0;
	ret = add_arr_cmp(mini, add_arr, offset, idx);
	return (ret);
}

int	add_env_assign(t_mini *mini, int idx, char **add_arr)
{
	int	jdx;
	int	count;
	int	ret;

	jdx = 0;
	count = 0;
	while (mini->buf[++jdx])
	{
		while (*(mini->buf[jdx]) == 0)
			jdx++;
		count++;
		if (mini->buf[jdx] == 0)
			break ;
		ret = cmp_key(mini, add_arr, jdx);
		if (ret == 1)
			continue ;
		else if (ret == -1)
			return (mini->err.malloc);
		add_arr[idx + count - 1] = ft_strdup(mini->buf[jdx]);
		if (!add_arr[idx + count - 1])
			return (mini->err.malloc);
	}
	return (0);
}

int	add_env_copy(t_mini *mini, char **add_arr, char ***envp)
{
	int	idx;

	idx = -1;
	while ((*envp)[++idx])
	{
		add_arr[idx] = ft_strdup((*envp)[idx]);
		if (!add_arr[idx])
		{
			ft_free(add_arr);
			return (mini->err.malloc);
		}
	}
	return (idx);
}
