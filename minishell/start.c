#include "minishell.h"

int	main_loop(t_mini *mini)
{
	int		ret;
	char	*str;

	while (1)
	{
		mini_term_init(*mini);
		signal(SIGINT, sig_handler);
		signal(SIGQUIT, SIG_IGN);
		str = readline("minishell $ ");
		if (!str)
			sig_ctrl_d();
		if (str == 0 || *str == 0)
		{
			free(str);
			continue ;
		}
		ret = mini_process(str, mini);
		rm_tmpfile(mini->pipe);
		add_history(str);
		ret = main_free(mini, str, ret);
		if (ret == mini->err.cmd)
			continue ;
		else if (ret == mini->err.path_malloc)
			return (mini->err.malloc);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_mini	mini;

	if (argc != 1 || argv[1] != 0)
	{
		mini.err.argv = -4;
		cmd_err(argv[1], mini.err.argv, &mini);
		return (0);
	}
	mini.exit_stat = 0;
	init_env(&mini.envp, envp);
	ori_term_init(mini);
	main_loop(&mini);
	return (0);
}
