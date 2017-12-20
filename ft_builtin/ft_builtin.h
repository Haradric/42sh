
#ifndef FT_BUILTIN_H
# define FT_BUILTIN_H

# include "../shell.h"
# include "hash_table.h"

extern	t_hash	**g_table;

int		builtin_cd(char ***env, int argc, char **argv);
int		builtin_setenv(char ***env, int argc, char **argv);
int		builtin_unsetenv(char ***env, int argc, char **argv);

int		ft_built_find_path(char **env, char *str); //

#endif
