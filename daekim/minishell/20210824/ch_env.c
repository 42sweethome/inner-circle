#include "minishell.h"

int	search_env(t_mini *mini, char **env, char *tmp, int len)
{
	int	idx;
	int	cmp;

	*env = getenv(tmp);
	if (*env == 0)
	{
		idx = -1;
		while ((*mini->envp)[++idx])
		{	
			cmp = ft_strncmp((*mini->envp)[idx], tmp, len);
			if (cmp == 0)
			{
				if ((*mini->envp)[idx][len] == '=')
				{
					*env = ft_strdup(&(*mini->envp)[idx][len + 1]);
					if (*env == 0)
						return (mini->err.malloc);
					break ;
				}
			}
		}
	}
	return (0);
}

int	copy_env(char *new, char *env_str, int i, t_mini *mini)
{
	char	*env;
	char	*tmp;
	int		len;
	int		idx;
	int		ret;

	len = 0;
	while (al_num_under(env_str[i + len + 1]))
		len++;
	if (len == 0)
		return (i);
	tmp = ft_calloc(len + 1, sizeof(char));
	if (tmp == 0)
		return (mini->err.malloc);
	idx = -1;
	while (++idx < len)
			tmp[idx] = env_str[i + idx + 1];
	ret = search_env(mini, &env, tmp, len);
	if (ret == mini->err.malloc)
		return (mini->err.malloc);
	ft_strlcpy(new, env, ft_strlen(env) + 1);
	return (i + len + 1);
}

int	check_env(char *env_str, int i, t_mini *mini)
{
	char	*tmp;
	char	*env;
	int		len;
	int		idx;
	int		ret;

	len = 0;
	while (al_num_under(env_str[i + len + 1]))
		len++;
	tmp = ft_calloc(len + 1, sizeof(char));
	if (tmp == 0)
		return (mini->err.malloc);
	idx = -1;
	while (++idx < len)
		tmp[idx] = env_str[i + idx + 1];
	ret = search_env(mini, &env, tmp, len);
	if (ret == mini->err.malloc)
		return (mini->err.malloc);
	mini->env_len = mini->env_len + ft_strlen(env) - len;
	if (len != 0)
		mini->dollar++;
	return (i + len);
}
