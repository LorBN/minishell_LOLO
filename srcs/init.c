#include "minishell.h"

static size_t	ms_nb_elem_char_array(char **arr)
{
	unsigned int    i;
	size_t          count;

	i = 0;
	count = 0;
	while (arr[i])
	{
    	count++;
        i++;
    }
	return (count);
}

void    ms_init_envp(int ac, char *argv[], char *envp[])
{
	unsigned int    i;

	(void)ac;
	(void)argv;
	g_envp = (char **)ft_calloc(ms_nb_elem_char_array(envp) ,sizeof(char *));
	i = 0;

	while (envp[i])
	{
		if (!(g_envp[i] = ft_strdup(envp[i])))
			ms_exit();
        i++;
	}
    g_envp[i] = NULL;
    return;
}