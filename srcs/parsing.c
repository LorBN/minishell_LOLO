#include "minishell.h"

char	*ms_command(t_cmd *cmd)
{
	int splitflag;   // flag = 1  if command separated by ;  /  flag = 0 if reach the end of the line

	splitflag = 0;
    cmd->i = 0;
	cmd->quoteflag = 0;
	cmd->line = cmd->rest;
	while (cmd->line[cmd->i] != '\0')
	{
        ms_quoteflag(cmd);
		if (cmd->line[cmd->i] == ';')
		{
			if (ms_check_comma(cmd) == 1)
			{
				splitflag = 1;
				break;
			}
		}
		cmd->i++;
	}
	if ((S_Q & cmd->quoteflag) && (D_Q & cmd->quoteflag))   // if quotes are opened at the end of the command
		printf("ERROR : quote opened !!");
	if (splitflag == 0)   // no ; separating commands (no split done) = end of line
	{
	//	printf("cmd line = %s\n", cmd->line);
		cmd->rest = NULL;
	}
	printf("CMD LINE = %s\n", cmd->line);

	// PUT ALL THE FUNCTIONS TO ANALYSE EACH COMMAND HERE !!!!!!!
	//ms_parsing(cmd);

	//return (cmd->quoteflag);     //keep it if we want to print char bitwise value
	return (cmd->rest);
}




int     ms_parsing(t_cmd *cmd)
{
    cmd->i = 0;
    cmd->quoteflag = 0;
    while (cmd->line[cmd->i] != '\0')
    {
    //      char a = cmd->quoteflag;
    // int i;
    //     for (i = 0; i < 8; i++) {
    //      printf("%d", !!((a << i) & 0x80));
    //     }
    //     printf("\n");

        ms_quoteflag(cmd);
        ms_check_quotes(cmd);
        cmd->i++;
    }
    
    // char a = cmd->quoteflag;
    // int i;
    //     for (i = 0; i < 8; i++) {
    //      printf("%d", !!((a << i) & 0x80));
    //     }
    //     printf("\n");
    return (1);
}
