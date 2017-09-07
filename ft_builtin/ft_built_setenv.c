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

#include "ft_builtin_private.h"

int		ft_count_env(char **en)
{
	int	w;

	w = 0;
	while (en[w])
		w++;
	return (w);
}

void	ft_add_env(char ***env, char **mas)
{
	int		w;
	char	**new;
	int		i;

	i = 0;
	w = ft_count_env((*env));
	if (!(new = (char **)malloc(sizeof(char *) * (w + 2))))
		return ;
	while ((*env)[i])
	{
		new[i] = ft_strdup((*env)[i]);
		free((*env)[i]);
		i++;
	}
	free((*env));
	new[i] = ft_strdup(mas[1]);
	new[i + 1] = NULL;
	*env = new;
}

int		ft_ch_env(char **mas)
{
	int	i;

	i = 0;
	if (mas[2] != NULL)
	{
		ft_putendl("usage: setenv [env]=...");
		return (0);
	}
	while (mas[1][i] != '\0')
	{
		if (mas[1][i] == '=')
			return (1);
		i++;
	}
	ft_putendl("usage: setenv [env]=...");
	return (0);
}

int	ft_built_setenv(char ***env, char **mas)
{
	int		w;
	int		i;

	if (!(ft_ch_env(mas)))
		return (0);
	w = 0;
	while ((*env)[w])
	{
		i = 0;
		while ((*env)[w][i] == mas[1][i])
		{
			if ((*env)[w][i] == '=')
			{
				free((*env)[w]);
				(*env)[w] = ft_strdup(mas[1]);
				return (0);
			}
			i++;
		}
		w++;
	}
	ft_add_env(env, mas);
	return (0);
}

