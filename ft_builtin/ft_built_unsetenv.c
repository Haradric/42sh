
#include "ft_builtin.h"

int		builtin_unsetenv(char ***env, int argc, char **argv)
{
	if (argc != 2)
	{
		error("42sh:", "usage: unsetenv key");
		return (0); // ???
	}
	env_remove(env, argv[1]);
	if (!ft_strcmp(argv[1], "PATH"))
		free_hash_table(g_table);
	return (0);
}
