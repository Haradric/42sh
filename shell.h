/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 16:09:44 by olyuboch          #+#    #+#             */
/*   Updated: 2017/10/01 16:09:46 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include <stdio.h>
# include <string.h>

# include "libft/libft.h"
# include "env.h"
# include "ft_readline.h"
# include "ft_hash_table.h"
# include "ft_lexer.h"
# include "ft_parser.h"
# include "ft_free.h"
# include "ft_preprocessing.h"
# include "ft_history.h"
# include "ft_signals.h"

char	*ft_join_quote(char *a, char *b);

char	*ft_freedup(char *str, int f);
char	*ft_freejoin(char *s1, char *s2, int f);

void	error(const char *error_msg, const char *str);
void	terminate(const char *error_msg, const char *str);
void	ft_perror(const char *error_msg, const char *str);

#endif
