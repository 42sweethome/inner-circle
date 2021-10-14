#include "minishell.h"

int	check_option_n(t_mini *mini)
{
	int	i;
	int	j;

	i = mini->first;
	while (mini->buf[++i])
	{
		if (mini->buf[i][0] == '-')
		{
			j = 0;
			while (mini->buf[i][++j] == 'n')
				;
			if (mini->buf[i][j] == 0)
				mini->option_n++;
			else
				break ;
		}
		else
			break ;
	}
	return (mini->option_n);
}

int	echo_upper(t_mini *mini, int *idx)
{
	if (*idx == mini->first + 1 && \
		!ft_strncmp(mini->buf[mini->first + 1], "-n", 3))
		(*idx)++;
	if (mini->buf[*idx] == 0)
		return (1);
	printf("%s", mini->buf[*idx]);
	if (mini->buf[*idx + 1] != 0)
		printf(" ");
	if (mini->buf[*idx + 1] == 0 && \
		ft_strncmp(mini->buf[mini->first + 1], "-n", 3))
		printf("\n");
	return (0);
}

int	echo_lower(t_mini *mini, int *idx)
{
	if (*idx == mini->first + 1)
		*idx += check_option_n(mini);
	if (mini->buf[*idx] == 0)
		return (1);
	printf("%s", mini->buf[*idx]);
	if (mini->buf[*idx + 1] != 0)
		printf(" ");
	if (mini->buf[*idx + 1] == 0 && mini->option_n == 0)
		printf("\n");
	return (0);
}

void	ft_echo(t_mini *mini)
{
	int	idx;

	idx = mini->first;
	while (mini->buf[++idx])
	{
		if (mini->upper == 1)
		{
			if (echo_upper(mini, &idx))
				break ;
		}
		else
		{
			if (echo_lower(mini, &idx))
				break ;
		}
	}	
}
