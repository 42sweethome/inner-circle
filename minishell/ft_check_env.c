/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonkang <sonkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:11:35 by sonkang           #+#    #+#             */
/*   Updated: 2021/11/17 11:11:37 by sonkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_exit_stat(t_mini *mini, char **env, int *len)
{
	*env = ft_itoa(mini->exit_stat);
	*len = ft_strlen(*env);
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

int	check_tmp_alloc(char *env_str, char **tmp, int i, int *len)
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

int	check_env(char *env_str, int i, t_mini *mini)
{
	char	*tmp;
	char	*env;
	int		len;
	int		ret;

	if (check_tmp_alloc(env_str, &tmp, i, &len) == -1)
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
	mini->env_len = mini->env_len + ft_strlen(env) - len;
	if (len != 0 || (env_str[i + 1] == '"' && mini->d_quo == 0))
		mini->dollar++;
	if (len == 0)
		mini->pre_flag = 1;
	free(env);
	free(tmp);
	return (i + len);
}
