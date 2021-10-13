#include "minishell.h"

int	special_char4(int c)
{
	if (c == ' ' || c == '>' || c == '<' || c == '|' || \
			c == '\0' || c == '$')
		return (0);
	return (1);
}

int	special_char3(int c)
{
	if (c == ' ' || c == '>' || c == '<' || c == '|' || \
			c == '\0')
		return (0);
	return (1);
}

int	special_char2(int c)
{
	if (c == '?' || c == '"' || c == '\'' || c == '>' || c == '<' || \
			c == '|' || c == '$')
		return (0);
	return (1);
}

int	special_char(int c)
{
	if (c == '?' || c == ' ' || c == 0 || c == '>' || c == '<' || \
			c == '|' || c == '"' || c == '\'' || c == '$')
		return (0);
	return (1);
}
