/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdemeshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 15:35:22 by vdemeshk          #+#    #+#             */
/*   Updated: 2017/10/01 15:35:25 by vdemeshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_FREE_H
# define __FT_FREE_H
# include "ft_parser.h"
# include "ft_readline.h"
# include "hash_table.h"
# include "ft_exec.h"

void	free_str_array(char **arr);
void	ft_free_syntax_tree(t_syntax_tree *tree);
void	ft_free_history(void);
void	ft_free_proc(t_proc **proc);
void	free_token(t_token *token);
void	free_token_list(t_token *token);

#endif
