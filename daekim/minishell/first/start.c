#include "minishell.h"

int	parshing(char *str, t_mini *mini)
{
	
	// 최초 공백 무시 필요
	mini->buf = space_split(str, ' ', mini);
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
		parshing(str, &mini);
		i = -1;
		while (mini.buf[++i])
			printf("%s\n", mini.buf[i]);
        free(str);
	}
	return (0);
}
