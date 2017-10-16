/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_unsetenv.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 16:26:01 by olyuboch          #+#    #+#             */
/*   Updated: 2017/09/07 16:26:03 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_builtin.h"

int		ft_built_unsetenv(char ***env, char **arg)
{
	int		i;

	if (!env || !*env || !arg)
		return (0);
	i = 0;
	while (arg[i])
		i++;
	if (!ft_strcmp(arg[1], "PATH"))
		free_hash_table(g_table);
	if (i == 2)
	{
		ft_env_remove(env, arg[1]);
		return (0);
	}
	write(2, "usage: unsetenv key\n", 20);
	return (0);
}
