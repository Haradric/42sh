/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_setenv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 15:44:29 by olyuboch          #+#    #+#             */
/*   Updated: 2017/09/07 15:52:20 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_builtin.h"

int		ft_built_setenv(char ***env, char **arg)
{
	char	*key;
	char	*eq;
	int		i;

	if (!env | !*env | !arg)
		return (0);
	i = 0;
	while (arg[i])
		i++;
	if (i == 2 && (eq = ft_strchr(arg[1], '=')))
	{
		key = ft_strsub(arg[1], 0, eq - arg[1]);
		ft_env_set(env, key, eq + 1);
		if (!ft_strcmp(key, "PATH"))
		{
			free_hash_table(g_table);
			g_table = ft_hash_table(*env);
		}
		free(key);
		return (0);
	}
	write(2, "usage: setenv key=value\n", 24);
	return (0);
}
