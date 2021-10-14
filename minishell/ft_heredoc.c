#include "minishell.h"

int	check_line(char *line, int fd, char *delimeter)
{
	if (!line)
	{
		close(fd);
		return (-1);
	}
	if (!ft_strncmp(line, delimeter, ft_strlen(delimeter) + 1))
	{
		close(fd);
		free(line);
		return (1);
	}
	return (0);
}

void	make_tmp(char *delimeter, int idx)
{
	int		fd;
	char	*str;
	char	*tmp;
	char	*line;

	str = ft_itoa(idx);
	tmp = ft_strjoin("/tmp/.", str);
	free(str);
	fd = open(tmp, O_RDWR | O_CREAT, 0666);
	while (1)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_IGN);
		line = readline("> ");
		if (check_line(line, fd, delimeter) != 0)
			break ;
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
	}
	free(tmp);
}

void	tmp_heredoc(t_mini *mini)
{
	int	idx;
	int	jdx;

	idx = -1;
	while (++idx < mini->pipe + 1)
	{
		jdx = -1;
		while (++jdx < mini->red_cnt[idx])
		{
			if (!ft_strncmp(mini->red[idx][jdx].redir, "<<", 3))
				make_tmp(mini->red[idx][jdx].file, idx);
		}
	}
}
