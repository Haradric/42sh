/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_globbing.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 16:46:34 by mvarga            #+#    #+#             */
/*   Updated: 2017/09/28 16:57:48 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GLOBBING_H
# define FT_GLOBBING_H

# include <stdlib.h>
# include <string.h>
# include "ft_parser.h"
# include <dirent.h>
# include "ft_env.h"
# include "../libft/libft.h"

# define U(c) ((c) & 0377)

extern char		**g_env;

void			ft_globbing_call(t_syntax_tree *arguments);
void			ft_globbing_callback(char *str);
int				ft_globbing_is_pattern(char *pattern);
int				ft_match(char *s, char *p, int cur_char, int c);
int				ft_brackets(char **p, int cur_char);
void			ft_tilda_exchange(t_syntax_tree *arguments);

#endif
