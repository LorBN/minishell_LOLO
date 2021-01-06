#include "minishell.h"

char	*ms_get_env_var(char *envv)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = ft_strjoin(envv, "=");
	while (g_envp[i])
	{
		if (ft_strncmp(g_envp[i], tmp, strlen(tmp)) == 0)
		{
			free(tmp);
			return (ft_strchr(g_envp[i], '=') + 1);
		}
        i++;
	}
	free(tmp);
	return (NULL);
}

int		ms_check_cmd_validity(t_cmd *cmd, char *envv)
{
	// int i;

	// i = 0;
	cmd->i += ft_strlen(envv);
	printf("i = %d\n", cmd->i);
	while (cmd->line[cmd->i] == ' ')
		cmd->i++;
	if (cmd->line[cmd->i] != '\0')
	{
		printf("unvalid command\n");
		return (-1);
	}
	else
		return (1);
}