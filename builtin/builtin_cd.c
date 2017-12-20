
#include "builtin.h"

static void change_env(char ***env)
{
	char	*oldpwd;
	char	*cwd;

	oldpwd = env_get(*env, "PWD");
	env_set(env, "OLDPWD", oldpwd);
	cwd = NULL;
	env_set(env, "PWD", getcwd(cwd, 0));
	free(cwd);
}

int			builtin_cd(char ***env, int argc, char **argv)
{
	char	*pwd;

	if (argc == 1)
		pwd = env_get(*env, "HOME");
	else if (argc == 2 && !ft_strcmp(argv[1], "-"))
		pwd = env_get(*env, "OLDPWD");
	else if (argc == 2)
		pwd = (char *)argv[1];
	else
	{
		error("cd:", "too much arguments");
		return (-1);
	}
	if (chdir(pwd))
	{
		ft_perror("cd:", pwd);
		return (-1);
	}
	change_env(env);
	if (argc == 2 && !ft_strcmp(argv[1], "-"))
		ft_putendl(env_get(*env, "PWD"));
	return (0);
}
