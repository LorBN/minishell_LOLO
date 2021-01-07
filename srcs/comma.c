#include "minishell.h"


int		ms_check_comma(t_cmd *cmd)
{
	if	((!(S_Q & cmd->quoteflag)) && (!(D_Q & cmd->quoteflag)) 
		&& (cmd->line[cmd->i-1] != 92))     // 92 = '\'
	{
		//printf("new command to split !\n");
		cmd->line[cmd->i] = 0;
		cmd->rest = ft_strdup(cmd->line + (cmd->i+1));
		//printf("cmd line = %s\n", cmd->line);
		//printf("rest line = %s\n", cmd->rest);
		return (1);
	}
	else
		//printf("';' is printed as its value\n");
	return (0);
}
