#include "minishell.h"

void		ms_check_quotes(t_cmd *cmd)
{
    if (cmd->line[cmd->i] == '\'')
    {
        if (D_Q & cmd->quoteflag)
		    cmd->quoteflag &= 0b111111110;
    }
    if (cmd->line[cmd->i] == '"')
    {
        if (S_Q & cmd->quoteflag)
            cmd->quoteflag &= 0b11111101;
    }
    return ;
}