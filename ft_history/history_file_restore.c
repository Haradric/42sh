/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_file_restore.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 14:45:37 by olyuboch          #+#    #+#             */
/*   Updated: 2017/10/01 15:29:43 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_history.h"

void	history_file_restore(const char *filename)
{
	int		fd;
	char	*path;
	char	*line;

	g_history = NULL;
	if (!g_env || !filename || filename[0] != '~')
		return ;
	path = ft_strjoin(env_get(g_env, "HOME"), filename + 1);
	if ((fd = open(path, O_RDONLY | O_CREAT)) == -1)
	{
		ft_perror("42sh:", path);
		return ;
	}
	while (get_next_line(fd, &line))
	{
		ft_add_to_history(&g_history, line);
		free(line);
		line = NULL;
	}
	close(fd);
	free(path);
}
