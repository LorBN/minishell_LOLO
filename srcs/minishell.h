#ifndef MINISHELL_H
# define MINISHELL_H
# define S_Q 1
# define D_Q 2


/*
** -------------------------- External Headers ---------------------------------
*/

# include "../libs/libft/libft.h"
#include "../libs/GNL/get_next_line.h"
# include <stdio.h>
# include <unistd.h>
//# include <linux/limits.h>
 # include <limits.h> // pour mac : vérifier s'il y a un #define PATH_MAX 4096 
# include <errno.h>
# include <string.h>


typedef struct      s_cmd			
{
	char	*line;
    int		i;
	char	quoteflag;
	char	*rest;
}				    t_cmd;

typedef struct		s_allcmd
{
    char	*cmd;
	struct	s_allcmd *next;
	struct	s_allcmd *previous;
}					t_allcmd;




/*
** -------------------------- Global variables ---------------------------------
*/

char    **g_envp;

/*
** --------------------------------- Defines -----------------------------------
*/

/*
** ------------------------- Enum Definitions ----------------------------------
*/

/*
** ------------------------- Structure Definitions -----------------------------
*/

/*
** -----------------------------------------------------------------------------
** ------------------------------- Sources -------------------------------------
** -----------------------------------------------------------------------------
*/

/*
** ---------------------------------- main.c -----------------------------------
*/

int    main(int ac, char *argv[], char *envp[]);

/*
** ---------------------------------- init.c -----------------------------------
*/

void    ms_init_envp(int ac, char *argv[], char *envp[]);

/*
** -------------------------------- display.c ----------------------------------
*/

void    ms_display_prompt_message();
int		ms_cmd_list(t_cmd *cmd);


/*
** --------------------------------- comma.c ----------------------------------
*/


int		ms_quoteflag(t_cmd *cmd);
int		ms_check_comma(t_cmd *cmd);

/*
** --------------------------------- quotes.c ----------------------------------
*/

void	ms_check_quotes(t_cmd *cmd);


/*
** --------------------------------- parsing.c ----------------------------------
*/

char	*ms_command(t_cmd *cmd);
int     ms_parsing(t_cmd *cmd);

/*
** ---------------------------------- utils.c ----------------------------------
*/

char	*ms_get_env_var(char *envv);
int		ms_check_cmd_validity(t_cmd *cmd, char *envv);

/*
** ---------------------------------- exit.c -----------------------------------
*/

void	ms_exit(void);

/*
** ---------------------------------- free.c -----------------------------------
*/

void	ms_free_char_array(char **arr);

/*
** ---------------------------------- pwd.c -----------------------------------
*/

void	ms_pwd(void);

/*
** ---------------------------------- env.c -----------------------------------
*/

int    ms_env(t_cmd *cmd);

#endif
