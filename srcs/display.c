#include "minishell.h"

int     ms_cmd_list(t_cmd *cmd)
{
    // int i;

    // i = 0;
    cmd->i = 0;
    while (cmd->line[cmd->i] == ' ')
        cmd->i++;
    if (cmd->line[cmd->i] != '\0')
    {
        if (ft_strncmp(cmd->line + cmd->i, "echo", strlen("echo")) == 0)
            printf("echo command\n");
        else if (ft_strncmp(cmd->line + cmd->i, "cd", strlen("cd")) == 0)
            printf("cd command\n");
        else if (ft_strncmp(cmd->line + cmd->i, "pwd", strlen("pwd")) == 0)
        {
            printf("pwd command\n");
            printf("cmd->i = %d\n", cmd->i);
            ms_pwd();
        }
        else if (ft_strncmp(cmd->line + cmd->i, "export", strlen("export")) == 0)
            printf("export command\n");
        else if (ft_strncmp(cmd->line + cmd->i, "unset", strlen("unset")) == 0)
            printf("unset command\n");
        else if (ft_strncmp(cmd->line + cmd->i, "env", strlen("env")) == 0)
        {
            printf("env command\n");
            ms_env(cmd);
        }
        else if (ft_strncmp(cmd->line + cmd->i, "exit", strlen("exit")) == 0)
            printf("exit command\n");
        else
            printf("command not in the list\n");
    }
    else
    {
        printf("no command\n");
        return (0);
    }
    return (1);
}

void    ms_display_prompt_message(void)
{
    char	buff[PATH_MAX + 1];
    char    *prompt;
    size_t  length;

    prompt = NULL;
	if (!(getcwd(buff, PATH_MAX + 1)))
        ms_exit();  
    length = ft_strlen(ms_get_env_var("HOME"));   
    if (!(prompt = ft_strjoin("~", &buff[length])))
        ms_exit();
    ft_putstr("\033[1m\033[33msim\033[31m♥\033[32mlolo\033[0m:\033[0;34m\033[1m");
    ft_putstr(prompt);
    ft_putstr("\033[0m$");
    free(prompt);
    // free(cwd); // qu'on m'explique
}
