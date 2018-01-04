/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 17:16:58 by mvarga            #+#    #+#             */
/*   Updated: 2017/09/28 17:38:29 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_LEXER_H
# define __FT_LEXER_H

# include "../shell.h"

typedef enum	e_token_type
{
	T_WHITESPACE,
	T_STRING,
	T_OP_BQUOTE,
	T_OP_PIPE,
	T_OP_REDIR,
	T_OP_SEMICOLON,
	T_OP_BRACKET,
	T_OP_LOGIC,
}				t_token_type;

typedef enum	e_token_subtype
{
	ST_ANY,
	ST_NONE,
	ST_QUOTE,
	ST_DQUOTE,
	ST_QUOTE_EOF,
	ST_DQUOTE_EOF,
	ST_LEFT,
	ST_RIGHT,
	ST_OR,
	ST_AND,
}				t_token_subtype;

typedef struct	s_token
{
	struct s_token	*prev;
	struct s_token	*next;
	t_token_type	type;
	t_token_subtype	subtype;
	char			*match;
	char			*data;
}				t_token;

typedef size_t	(*t_lexfunc)(char *s, t_token **token);

extern char		**g_env;

t_token			*token_scan_string(const char *string);
t_token			*get_token_list(const char *str);

#endif
