#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft/libft.h"
# include "gnl/get_next_line.h"

typedef struct s_mini
{
	char		**buf;
	int			quo;
}			t_mini;


char	**space_split(char *s, char c, t_mini *mini);
int	check_quo(char *s, char c, int i, t_mini *mini);
int	quo_while(char *s, char c, t_mini *mini, int i);

#endif
