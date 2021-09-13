#include "minishell.h"

char	**copy_arr(char ***envp)
{
	char **sort_arr;
	int idx;
	int size;

	size = -1;
	while ((*envp)[++size])
		;
	sort_arr = (char **)ft_calloc(size + 1, sizeof(char *));
	if (sort_arr == 0)
		return (0);
	idx = -1;
	while (++idx < size)
	{
		sort_arr[idx] = ft_strdup((*envp)[idx]);
		if (sort_arr[idx] == 0)
		{
			ft_free(sort_arr);
			return (0);
		}
	}
	return (sort_arr);
}

void	swap(char **str1, char **str2)
{
	char *tmp;

	tmp = *str1;
	*str1 = *str2;
	*str2 = tmp;
}

void	print_env(char **sort_arr)
{
	int idx;
	int jdx;
	int v_flag;

	idx = -1;
	while (sort_arr[++idx])
	{
		printf("declare -x ");
		v_flag = 0;
		jdx = -1;
		while (sort_arr[idx][++jdx])
		{
			printf("%c", sort_arr[idx][jdx]);
			if ((v_flag == 0 && sort_arr[idx][jdx] == '=') || \
					(sort_arr[idx][jdx + 1] == 0 && v_flag == 1))
			{
				v_flag = 1;
				printf("\"");
			}
		}
		printf("\n");
	}
}

int	show_env(t_mini *mini, char ***envp)
{
	char **sort_arr;
	int	idx;
	int	jdx;
	int	cmp;

	sort_arr = copy_arr(envp);
	if (sort_arr == 0)
		return (mini->err.malloc);
	idx = -1;
	while (sort_arr[++idx])
	{
		jdx = idx;
		while (sort_arr[++jdx])
		{
			cmp = ft_strncmp(sort_arr[idx], sort_arr[jdx], \
					ft_strlen(sort_arr[idx]));
			if (cmp > 0)
				swap(&sort_arr[idx], &sort_arr[jdx]);
		}
	}
	print_env(sort_arr);
	return (0);
}

int	cmp_key(t_mini *mini, char **add_arr, int offset)
{
	int	idx;
	int	jdx;

	idx = -1;
	while (mini->buf[offset][++idx])
		if (mini->buf[offset][idx] == '=')
			break ;
	if (!mini->buf[offset][idx])
		return (1);
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
		{
			ft_free(add_arr);
			return (mini->err.malloc);
		}
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

int	add_env_alloc(t_mini *mini, char ***envp)
{
	char	**add_arr;
	int		idx;
	int		jdx;
	int		count;
	int		ret;

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
	idx = add_env_copy(mini, add_arr, envp);
	if (idx == mini->err.malloc)
		return (mini->err.malloc);
	ret = add_env_assign(mini, idx, add_arr);
	if (ret == mini->err.malloc)
	{
		ft_free(add_arr);
		return (mini->err.malloc);
	}
	*envp = add_arr;
	return (0);
}

int	ft_export(t_mini *mini, char ***envp)
{
	int idx;

	idx = mini->first;
	if (mini->buf[++idx] == 0)
	{
		if (show_env(mini, envp) == mini->err.malloc)
			return (mini->err.malloc);
	}
	else
		if (add_env_alloc(mini, envp) == mini->err.malloc)
			return (mini->err.malloc);
	return (0);
}

int	rm_env(t_mini *mini, char ***envp)
{
	char	**rm_arr;
	int		idx;
	int		jdx;
	int		flag;
	int		count;

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
	rm_arr = (char **)ft_calloc(count + 1, sizeof(char *));
	if (!rm_arr)
		return (mini->err.malloc);
	idx = -1;
	flag = 0;
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
			{
				ft_free(rm_arr);
				return (mini->err.malloc);
			}
		}
	}
	*envp = rm_arr;
	return (0);	
}

int ft_unset(t_mini *mini, char ***envp)
{
	int	idx;

	idx = mini->first;
	if (mini->buf[++idx] == 0)
		return (0);
	else
		if (rm_env(mini, envp) == mini->err.malloc)
			return (mini->err.malloc);
	return (0);
}
