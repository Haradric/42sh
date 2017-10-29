
#include "env.h"

char			**env_init(const char **environ)
{
	char	**env;
	int		i;

	i = 0;
	while (environ[i])
		i++;
	env = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (environ[i])
	{
		env[i] = ft_strdup(environ[i]);
		i++;
	}
	env[i] = NULL;
	return (env);
}

static void		env_add(char ***env, char *entry)
{
	char	**new_env;
	int		i;

	if (!env || !*env || !entry)
		return ;
	i = 0;
	while ((*env)[i])
		i++;
	if (!(new_env = malloc(sizeof(char *) * (i + 2))))
		return ;
	i = 0;
	while ((*env)[i])
	{
		new_env[i] = (*env)[i];
		i++;
	}
	new_env[i] = entry;
	new_env[i + 1] = NULL;
	free(*env);
	*env = new_env;
}

void			env_set(char ***env, const char *key, const char *val)
{
	char	*entry;
	size_t	len;
	int		i;

	if (!env || !*env || !key)
		return ;
	len = ft_strlen(key);
	entry = ft_memalloc(len + ft_strlen(val) + 2);
	ft_strcat(ft_strcat(ft_strcat(entry, key), "="), val);
	i = 0;
	while ((*env)[i])
	{
		if (!ft_strncmp((*env)[i], key, len) && (*env)[i][len] == '=')
			break ;
		i++;
	}
	if ((*env)[i])
	{
		free((*env)[i]);
		(*env)[i] = entry;
	}
	else
		env_add(env, entry);
}

char			*env_get(char **env, const char *key)
{
	size_t	len;
	int		i;

	if (!key)
		return (NULL);
	len = ft_strlen(key);
	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], key, len) && env[i][len] == '=')
			return (&env[i][len + 1]);
		i++;
	}
	return (NULL);
}

void			env_remove(char ***env, const char *key)
{
	size_t	len;
	int		i;

	if (!env || !key)
		return ;
	len = ft_strlen(key);
	i = 0;
	while ((*env)[i])
	{
		if (!ft_strncmp((*env)[i], key, len) && (*env)[i][len] == '=')
			break ;
		i++;
	}
	if (!(*env)[i])
		return ;
	free((*env)[i]);
	while ((*env)[i + 1])
	{
		(*env)[i] = (*env)[i + 1];
		i++;
	}
	(*env)[i] = NULL;
}
