#include "minishell.h"

int    ms_env(t_cmd *cmd)
{
    int i;

    i = 0;
    if (ms_check_cmd_validity(cmd, "env") == -1)
        return (-1);
    while (g_envp[i])
	{
		ft_putstr(g_envp[i]);
        write(1, "\n", 1);
        i++;
	}
    return (1);
}