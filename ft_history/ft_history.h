/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 14:04:05 by olyuboch          #+#    #+#             */
/*   Updated: 2017/10/01 15:28:42 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HISTORY_H
# define FT_HISTORY_H

# include <stdio.h>
# include <fcntl.h>
# include <sys/ioctl.h>

# include "ft_readline.h" //
# include "builtin.h"
# include "ft_exec.h"

# define GNL_BUFF 8

typedef struct		s_fd
{
	int				fd;
	char			*s_tmp;
	struct s_fd		*next;
}					t_fd;

//typedef struct		s_his
//{
//	char			*tory;
//	char			*tmp;
//	struct s_his	*prev;
//	struct s_his	*next;
//}					t_his;

extern char		**g_env;
extern t_his	*g_history;

void			history_file_restore(const char *filename);
void			history_free(t_his **list);
int				get_next_line(const int fd, char **line);

void			ft_history_load(char *str, int fl);
int				ft_history_print(t_proc **proc);
void			ft_history_error(t_proc **proc, char *er);
int				ft_history_stdout_clear(t_proc **proc);
int				ft_history_stdin(t_proc **proc);
t_his			*ft_history_up(void);
t_his			*ft_history_dwn(void);

#endif
