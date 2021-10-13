#include "minishell.h"

int	env_exit_stat(t_mini *mini, char **env, int *len)
{
	*env = ft_itoa(mini->exit_stat);
	*len = 1;
	return (0);
}

int	search_env(t_mini *mini, char **env, char *tmp, int len)
{
	int	ret;

	len = 0;
	ret = ft_getenv(mini, env, tmp);
	if (ret == mini->err.malloc)
		return (mini->err.malloc);
	if (ret == 0)
		mini->env_flag = 1;
	return (0);
}

void	check_after_dollar(t_mini *mini, char *env_str, char *new, int i)
{
	if ((env_str[i + 1] != '\'' && env_str[i + 1] != '"') \
	|| !special_char4(env_str[i + 1]))
		*new = '$';
	else if (mini->d_quo == 1 || mini->s_quo == 1)
		*new = '$';
}

int	tmp_alloc(char *env_str, char **tmp, int i, int *len)
{
	int	idx;

	*len = 0;
	while (special_char(env_str[i + *len + 1]))
		(*len)++;
	*tmp = ft_calloc(*len + 1, sizeof(char));
	if (*tmp == 0)
		return (-1);
	idx = -1;
	while (++idx < *len)
		(*tmp)[idx] = env_str[i + idx + 1];
	return (0);
}

int	copy_env(char *new, char *env_str, int i, t_mini *mini)
{
	char	*env;
	char	*tmp;
	int		len;
	int		ret;

	if (tmp_alloc(env_str, &tmp, i, &len) == -1)
		return (mini->err.malloc);
	if (env_str[i + 1] == '?')
		ret = env_exit_stat(mini, &env, &len);
	else
		ret = search_env(mini, &env, tmp, len);
	if (ret == mini->err.malloc)
	{
		free(tmp);
		return (mini->err.malloc);
	}
	if (len == 0 && !special_char(env_str[i + 1]))
		check_after_dollar(mini, env_str, new, i);
	else
		ft_strlcpy(new, env, ft_strlen(env) + 1);
	free(tmp);
	free(env);
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
	while (special_char(env_str[i + len + 1]))
		len++;
	tmp = ft_calloc(len + 1, sizeof(char));
	if (tmp == 0)
		return (mini->err.malloc);
	idx = -1;
	while (++idx < len)
		tmp[idx] = env_str[i + idx + 1];
	if (env_str[i + 1] == '?')
		ret = env_exit_stat(mini, &env, &len);
	else
		ret = search_env(mini, &env, tmp, len);
	if (ret == mini->err.malloc)
	{
		free(tmp);
		return (mini->err.malloc);
	}
	mini->env_len = mini->env_len + ft_strlen(env) - len;
	if (len != 0 || env_str[i + 1] == '"')
		mini->dollar++;
	if (len == 0)
		mini->pre_flag = 1;
	free(env);
	free(tmp);
	return (i + len);
}
