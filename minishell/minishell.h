#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include "libft/libft.h"
# include "gnl/get_next_line.h"


# include <fcntl.h>
# include <termios.h>
# include <curses.h>
# include <term.h>

typedef	struct s_err
{
	int			path_malloc;
	int			split_malloc;
	int			malloc;
	int			only_space;
	int			pipe;
	int			cmd;
	int			quo;
	int			argv;
	int			redirect;
}			t_err;

typedef struct s_redir
{
	char	*file;
	char	*redir;
	//int		cnt;
}			t_redir;

typedef struct s_pipe
{
	char	**temp;
	char	*cmd;
	int		**fd;
	int		idx;
	int		jdx;
	int		count;
	int		*pid;
	int		pid_idx;
	int		status;
	int		initial;
}			t_pipe;

typedef struct s_mini
{
	char		**buf;
	char		***envp;
	char		**path;
	int			std_in;
	int			std_out;
	int			*pipe_idx;
	int			s_quo;
	int			d_quo;
	int			cnt_quo;
	int			odd_quo;
	int			env_len;
	int			env_flag;
	int			pre_flag;
	int			quo_flag;
	int			dollar;
	int			first;
	int			pipe;
	int			redirect;			
	int			exit_stat;
	int			*red_cnt;
	struct termios ori_term;
	struct termios mini_term;
	t_err		err;
	t_pipe		pipe_struct;
	t_redir		**red;
}			t_mini;

int		space_split(char *s, char c, t_mini *mini);
int		check_quo(char *s, char c, int i, t_mini *mini);
int		quo_while(char *s, char c, t_mini *mini, int i);
int		case_quo(char *str, int *idx, t_mini *mini);
int		cmd_err(char *cmd, int err_num, t_mini *mini);
int		check_cmd(char *cmd, t_mini *mini, char ***envp);
char	ft_free(char **new);
int		special_char(int c);
int		special_char2(int c);
int		special_char3(int c);
int		special_char4(int c);
int		check_env(char *env_str, int i, t_mini *mini);
int		copy_env(char *new, char *env_str, int i, t_mini *mini);
void	ft_echo(t_mini *mini);
void	ft_pwd(void);
void	ft_env(char ***envp);
int		ft_getenv(t_mini *mini, char **env, char *str);
int		ft_chdir(t_mini *mini);
int		ft_export(t_mini *mini, char ***envp);
int 	ft_unset(t_mini *mini, char ***envp);
void	ft_exit(t_mini *mini);
int		pipe_execve(t_mini *mini, t_pipe *pi);
int		check_pipe_pos(t_mini *mini);
int     func_redir(t_mini *mini);
void    tmp_heredoc(t_mini *mini);
void	rm_tmpfile(int cnt);
void    redirect_fd(t_redir *red, int cnt, int idx);
int		my_execve(t_mini *mini, char *cmd, char ***envp);
void	sig_handler(int	signum);
void	sig_handler_2(int	signum);
void	sig_ctrl_d(void);
void	ori_term_init(t_mini mini);
void	mini_term_init(t_mini mini);

#endif