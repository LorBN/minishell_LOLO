#include "minishell.h"

void	ms_free_char_array(char **arr) 
{
	int i;

	if (!arr)
		return;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
        arr[i] = NULL;
        i++;
	}
	free(arr);
	arr = NULL;
}