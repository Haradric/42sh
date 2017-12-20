/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 15:41:05 by olyuboch          #+#    #+#             */
/*   Updated: 2017/09/07 15:41:07 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_BUILTIN_H
# define __FT_BUILTIN_H

# include "../shell.h"
# include "env.h"
# include "ft_readline.h"
# include "ft_hash_table.h"
# include "ft_free.h"

extern	t_hash	**g_table;

int		builtin_cd(char ***env, int argc, char **argv);
int		builtin_setenv(char ***env, int argc, char **argv);
int		builtin_unsetenv(char ***env, int argc, char **argv);

int		ft_built_find_path(char **env, char *str);

#endif
