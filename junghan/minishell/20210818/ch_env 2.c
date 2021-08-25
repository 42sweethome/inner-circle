#include "minishell.h"

int	copy_env(char *new, char *env_str, int i, t_mini *mini)
{
	char	*tmp;
	int		len;
	int		idx;

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
	ft_strlcpy(new, getenv(tmp), ft_strlen(getenv(tmp)) + 1);
	return (i + len + 1);
}

int	check_env(char *env_str, int i, t_mini *mini)
{
	char	*tmp;
	int		len;
	int		idx;

	len = 0;
	while (al_num_under(env_str[i + len + 1]))
		len++;
	tmp = ft_calloc(len + 1, sizeof(char));
	if (tmp == 0)
		return (mini->err.malloc);
	idx = -1;
	while (++idx < len)
		tmp[idx] = env_str[i + idx + 1];
	mini->env_len = mini->env_len + ft_strlen(getenv(tmp)) - len;
	if (len != 0)
		mini->dollar++;
	return (i + len);
}
