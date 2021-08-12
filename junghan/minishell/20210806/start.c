#include "minishell.h"

void	mini_init(t_mini *mini)
{
	mini->s_quo = 0;
	mini->d_quo = 0;
	mini->cnt_rvslash = 0;
	mini->cnt_quo = 0;
}

int	parshing(char *str, t_mini *mini)
{
	// 최초 공백 무시 필요
	mini_init(mini);
	mini->buf = space_split(str, ' ', mini);
	if (mini->buf == NULL)
		return (-1);
	return (0);
}

int	main()
{
	char	*str;
	t_mini	mini;
	int		i;

	while (1)
	{
 		str = readline("minishell $ ");
		if (parshing(str, &mini))
			return (-1);
		i = -1;
		while (mini.buf[++i])
			printf("%s\n", mini.buf[i]);
        free(str);
	}
	return (0);
}
