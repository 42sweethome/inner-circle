#include "minishell.h"

typedef struct	s_list_p
{
	char			**args;
	int				length;
	int				type;
	int				pipes[2];
	struct s_list_p	*previous;
	struct s_list_p	*next;
}				t_list_p;

int list_rewind(t_list_p **list)
{
	while (*list && (*list)->previous)
		*list = (*list)->previous;
	return (EXIT_SUCCESS);
}

int exec_cmd(t_list_p *cmd, char **env)
{
	pid_t	pid;
	int		ret;
	int		status;
	int		pipe_open;

	ret = 1;
	pipe_open = 0;
	if (cmd->type == 1 || (cmd->previous && cmd->previous->type == 1))
	{
		pipe_open = 1;
		if (pipe(cmd->pipes))
			return (-1);
	}
	pid = fork();
	if (pid < 0)
		return (-1);
	else if (pid == 0)
	{
		if (cmd->type == 1
			&& dup2(cmd->pipes[1], 1) < 0)
			return (-1);
		if (cmd->previous && cmd->previous->type == 1
			&& dup2(cmd->previous->pipes[0], 0) < 0)
			return (-1);
		if ((ret = execve(cmd->args[0], cmd->args, env)) < 0)
		{
			return (-1);
		}
		exit(ret);
	}
	else
	{
		waitpid(pid, &status, 0);
		if (pipe_open)
		{
			close(cmd->pipes[1]);
			if (!cmd->next || cmd->type == 0)
				close(cmd->pipes[0]);
		}
		if (cmd->previous && cmd->previous->type == 1)
			close(cmd->previous->pipes[0]);
		if (WIFEXITED(status))
			ret = WEXITSTATUS(status);
	}
	return (ret);
}

int		pipe_execve(t_mini *mini)
{
	t_list_p	*cmds;

	cmds = NULL;

	t_list_p *head = (t_list_p*)malloc(sizeof(*head));
	head->args = NULL;
	head->length = 0;
	head->type = 1;
	head->previous = NULL;
	head->next = NULL;
	cmds = head;
	printf("0\n");	

	char	*test1[3] = {"/bin/cat", "a.c", NULL};
	cmds->args = test1;
///////////////////////////////////////////	
	t_list_p	*new;

	if (!(new = (t_list_p*)malloc(sizeof(*new))))
		return (-1);
	new->args = NULL;
	new->length = 0;
	new->type = 1;
	new->previous = NULL;
	new->next = NULL;
	if (cmds)
	{
		cmds->next = new;
		new->previous = cmds;
	}
	cmds = new;
	printf("1\n");	
	char	*test3[3] = {"/bin/cat", "b.c", NULL};
	cmds->args = test3;
///////////////////////////////////////////////
	t_list_p	*new2;

	if (!(new2 = (t_list_p*)malloc(sizeof(*new2))))
		return (-1);
	new2->args = NULL;
	new2->length = 0;
	new2->type = 1;
	new2->previous = NULL;
	new2->next = NULL;
	if (cmds)
	{
		cmds->next = new2;
		new2->previous = cmds;
	}
	cmds = new2;
	printf("2\n");	

	char	*testa[3] = {"/bin/cat", "c.c", NULL};
	cmds->args = testa;
//////////////////////////////////////////////////////
	t_list_p	*newa;

	if (!(newa = (t_list_p*)malloc(sizeof(*newa))))
		return (-1);
	newa->args = NULL;
	newa->length = 0;
	newa->type = 1;
	newa->previous = NULL;
	newa->next = NULL;
	if (cmds)
	{
		cmds->next = newa;
		newa->previous = cmds;
	}
	cmds = newa;
	printf("3\n");	

	char	*testb[3] = {"/bin/cat", "d.c", NULL};
	cmds->args = testb;
///////////////////////////////////////////////////////
	t_list_p	*newb;

	if (!(newb = (t_list_p*)malloc(sizeof(*newb))))
		return (-1);
	newb->args = NULL;
	newb->length = 0;
	newb->type = 1;
	newb->previous = NULL;
	newb->next = NULL;
	if (cmds)
	{
		cmds->next = newb;
		newb->previous = cmds;
	}
	cmds = newb;
	printf("4\n");	

	char	*test2[3] = {"/usr/bin/grep", "a", NULL};
	cmds->args = test2;
////////////////////////////////////////////////////////
	list_rewind(&cmds);
	mini->pipe++;
	while (mini->pipe--)
	{
		exec_cmd(cmds, *mini->envp);
		if (!cmds->next)
			break ;
		cmds = cmds->next;
	}
	return (mini->err.pipe);
}
