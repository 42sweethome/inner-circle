#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
//# include <readline/readline.h>
# include <readline/history.h>
# include "libft/libft.h"
# include "gnl/get_next_line.h"

typedef struct s_mini
{
	char		**buf;
	int			s_quo;
	int			d_quo;
	int			cnt_quo;
	int			cnt_rvslash;
	int			odd_quo;
	int			env_len;
	int			dollar;
}			t_mini;

int		space_split(char *s, char c, t_mini *mini);
int		check_quo(char *s, char c, int i, t_mini *mini);
int		quo_while(char *s, char c, t_mini *mini, int i);
int		case_quo(char *str, int *idx, t_mini *mini);
int		print_err(char *err_str);
int		cmd_err(char *cmd);
int		check_cmd(char *cmd);
int		al_num_under(int c);
int		check_env(char *env_str, int i, t_mini *mini);
int		copy_env(char *new, char *env_str, int i);
#endif
