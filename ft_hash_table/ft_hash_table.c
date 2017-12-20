/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 20:05:02 by olyuboch          #+#    #+#             */
/*   Updated: 2017/07/18 20:05:04 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "ft_hash_table.h"
#include "ft_free.h"

static void	init_table(t_hash **table, char **path)
{
	DIR				*dir;
	struct dirent	*entry;
	char			*filename;
	char			*tmp;
	int				i;

	i = 0;
	while (path[i])
	{
		dir = opendir(path[i]);
		while (dir && (entry = readdir(dir)))
		{
			tmp = ft_strjoin(path[i], "/");
			filename = ft_strjoin(tmp, entry->d_name);
			free(tmp);
			if (!access(filename, X_OK) && \
				(entry->d_type == DT_REG || entry->d_type == DT_LNK))
				ft_hash_set(table, entry->d_name, filename);
			free(filename);
		}
		if (dir)
			closedir(dir);
		i++;
	}
}

t_hash		**ft_hash_table(char **env)
{
	t_hash	**table;
	char	**path;

	if (!(path = ft_strsplit(env_get(env, "PATH"), ':')))
		return (NULL);
	table = ft_memalloc(sizeof(t_hash *) * HASH_SIZE + 1);
	init_table(table, path);
	free_str_array(path);
	return (table);
}

static void	free_elem(t_hash *elem)
{
	t_hash	*tmp;

	while (elem)
	{
		tmp = elem;
		elem = elem->next;
		free(tmp->command);
		free(tmp->filename);
		free(tmp);
	}
}

void		free_hash_table(t_hash ***table)
{
	int		i;

	if (!*table)
		return ;
	i = 0;
	while (i < HASH_SIZE)
	{
		if ((*table)[i])
			free_elem((*table)[i]);
		i++;
	}
	free(*table);
	*table = NULL;
}
