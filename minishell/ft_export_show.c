#include "minishell.h"

char	**copy_arr(char ***envp)
{
	char	**sort_arr;
	int		idx;
	int		size;

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

void	print_env(char **sort_arr)
{
	int	idx;
	int	jdx;
	int	v_flag;

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
				if (sort_arr[idx][jdx] == '=' && sort_arr[idx][jdx + 1] == 0)
					printf("\"");
			}
		}
		printf("\n");
	}
}

int	show_env(t_mini *mini, char ***envp)
{
	char	**sort_arr;
	int		idx;
	int		jdx;
	int		cmp;

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
	ft_free(sort_arr);
	return (0);
}

int	ft_export(t_mini *mini, char ***envp)
{
	int	idx;

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
