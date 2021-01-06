#include "minishell.h"

int		ms_quoteflag(t_cmd *cmd)
{
	if (cmd->line[cmd->i] == '\'')
	{
		//printf("' founded\n");
		if (!(S_Q & cmd->quoteflag))
		{
			    cmd->quoteflag |= S_Q;
		//	    printf("simple quote flag 1\n");
		}
		else
		{
			cmd->quoteflag &= 0b111111110;
		//	printf("simple quote flag 0\n");
		}
	}
	else if (cmd->line[cmd->i] == '"')
	{
		//printf("\" founded\n");
		if (!(D_Q & cmd->quoteflag))
		{
			cmd->quoteflag |= D_Q;
		//	printf("double quote flag 1\n");
		}
		else
		{
			cmd->quoteflag &= 0b11111101;
		//	printf("double quote flag 0\n");
		}
	}
	ms_check_quotes(cmd);
	return (1);
}

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


// char	*ms_command(t_cmd *cmd)
// {
// 	int splitflag;   // flag = 1  if command separated by ;  /  flag = 0 if reach the end of the line

// 	splitflag = 0;
//     cmd->i = 0;
// 	cmd->quoteflag = 0;
// 	cmd->line = cmd->rest;
// 	while (cmd->line[cmd->i] != '\0')
// 	{
//         ms_quoteflag(cmd);
// 		if (cmd->line[cmd->i] == ';')
// 			if (ms_check_comma(cmd) == 1)
// 			{
// 				splitflag = 1;
// 				break;
// 			}
// 		cmd->i++;
// 	}
// 	if ((S_Q & cmd->quoteflag) || (D_Q & cmd->quoteflag))   // if quotes are opened at the end of the command
// 		printf("ERROR : quote opened !!");
// 	if (splitflag == 0)   // no ; separating commands (no split done) = end of line
// 	{
// 	//	printf("cmd line = %s\n", cmd->line);
// 		cmd->rest = NULL;
// 	}
// 	printf("CMD LINE = %s\n", cmd->line);

// 	// PUT ALL THE FUNCTIONS TO ANALYSE EACH COMMAND HERE !!!!!!!
// 	ms_check_quotes(cmd);

// 	//return (cmd->quoteflag);     //keep it if we want to print char bitwise value
// 	return (cmd->rest);
// }
