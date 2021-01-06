#include "minishell.h"

int    main(int ac, char *argv[], char *envp[])
{
    t_cmd cmd;

    cmd.line = NULL;
	ms_init_envp(ac, argv, envp);
    while (1)
    {
        ms_display_prompt_message();
        get_next_line(1, &cmd.line);
        //printf("line = %s\n", cmd.line);
        cmd.rest = cmd.line;
        while (cmd.rest != NULL)
        {
            cmd.rest = ms_command(&cmd);    // cmd.rest become the rest of the line (next commands to split)
           // printf("cmd->rest = %s\n", cmd.rest);
        }
        // char a = ms_comma(&cmd);
        // int i;
        // for (i = 0; i < 8; i++) {
        //  printf("%d", !!((a << i) & 0x80));
        // }
        // printf("\n");
        //ms_cmd_list(&cmd);
        //break;
    }
	return (0);
}