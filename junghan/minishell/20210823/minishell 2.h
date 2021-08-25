#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <stdlib.h>
//# include <readline/readline.h>
# include <readline/history.h>
# include "libft/libft.h"
# include "gnl/get_next_line.h"

typedef	struct s_err
{
	int			malloc;
	int			cmd;
	int			quo;
	int			argv;
}			t_err;

typedef struct s_mini
{
	char		**buf;
//	char		**env;
	char		**path;
	int			s_quo;
	int			d_quo;
	int			cnt_quo;
	int			cnt_rvslash;
	int			odd_quo;
	int			env_len;
	int			dollar;
	int			first;
	t_err		err;
}			t_mini;

int		space_split(char *s, char c, t_mini *mini);
int		check_quo(char *s, char c, int i, t_mini *mini);
int		quo_while(char *s, char c, t_mini *mini, int i);
int		case_quo(char *str, int *idx, t_mini *mini);
int		cmd_err(char *cmd, int err_num, t_mini *mini);
int		check_cmd(char *cmd, t_mini *mini, char **envp);
char	ft_free(char **new);
int		al_num_under(int c);
int		check_env(char *env_str, int i, t_mini *mini);
int		copy_env(char *new, char *env_str, int i, t_mini *mini);
void	ft_echo(t_mini *mini);
void	ft_pwd(void);
void	ft_env(char **envp);
void	ft_chdir(t_mini *mini);
int	ft_export(t_mini *mini, /*char *cmd,*/ char **envp);

#endif
