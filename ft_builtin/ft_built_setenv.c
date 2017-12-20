
#include "ft_builtin.h"

int		builtin_setenv(char ***env, int argc, char **argv)
{
	if (argc != 3)
	{
		error("42sh:", "usage: setenv key value");
		return (0); // ???
	}
	env_set(env, argv[1], argv[2]);
	if (!ft_strcmp(argv[1], "PATH"))
	{
		free_hash_table(g_table);
		g_table = ft_hash_table(*env);
	}
	return (0);
}
