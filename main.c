/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 18:11:32 by mbraslav          #+#    #+#             */
/*   Updated: 2017/10/02 18:11:33 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char		*g_promt;
t_his		*g_history;
t_hash		**g_table;
t_token		*g_prev_tok;
t_token		*g_curr_sym;
t_token		*g_next_sym;
char		**g_env_g;
int			g_parent;
char		*g_lft;
char		*g_rgt;

static void	init_42(const char *const envp[])
{
	char	*shlvl_str;

	g_parent = 1;
	g_table = ft_hash_table((char **)envp);
	g_env_g = ft_env_init(envp);
	g_history = NULL;
	ft_history_upload();
	g_promt = ft_strdup("wtf?> ");
	ft_env_set(&g_env_g, "SHELL", "42sh");
	if ((shlvl_str = ft_env_get(g_env_g, "SHLVL")))
	{
		shlvl_str = ft_itoa(ft_atoi(shlvl_str) + 1);
		ft_env_set(&g_env_g, "SHLVL", shlvl_str);
		free(shlvl_str);
	}
	else
		ft_env_set(&g_env_g, "SHLVL", "1");
	ft_signals();
}

int			unclosed_quote(t_token *t, int i)
{
	while (t->next)
	{
		i += (t->type == T_OP_BQUOTE);
		t = t->next;
	}
	i += (t->type == T_OP_BQUOTE);
	if (i & 1)
	{
		g_promt = ("bquote> ");
		return (1);
	}
	if (t->subtype == ST_DQUOTE_EOF)
	{
		g_promt = ("dquote> ");
		return (1);
	}
	if (t->subtype == ST_QUOTE_EOF)
	{
		g_promt = ("quote> ");
		return (1);
	}
	return (0);
}

void		ft_find_quotes(t_token **tokens, char **cmd)
{
	char	*oldpromt;

	oldpromt = g_promt;
	while (unclosed_quote(*tokens, 0))
	{
		write(1, "\n", 1);
		token_free_all(*tokens);
		(*cmd) = ft_join_quote(*cmd, ft_readline());
		(*tokens) = token_scan_string((*cmd) ? (*cmd) : "");
	}
	g_promt = oldpromt;
}

/*
**	ft_tree_print(tree, 0);
*/

void		print_token(t_token *token)
{
	const char	*type[] = {"WHITESPACE", "STRING\t", "OP_BQUOTE", "OP_PIPE\t", \
		"OP_REDIR", "OP_SEMICOLON", "OP_BRACKET", "OP_LOGIC\t"};
	const char	*subtype[] = {"ANY\t\t", "NONE\t\t", "QUOTE\t", "DQUOTE\t", "QUOTE_EOF", \
		"DQUOTE_EOF", "LEFT\t\t", "RIGHT\t", "OR\t\t", "AND\t\t"};
	write(1, "\n----------------\n", 18);
	ft_putstr(token->data);
	ft_putstr("\t");
	ft_putstr(token->match);
	ft_putstr("\t");
	ft_putstr(type[token->type]);
	ft_putstr("\t");
	ft_putstr(subtype[token->subtype]);
	ft_putstr("\n");
	write(1, "\n----------------\n", 18);
}

void		print_token_list(t_token *list)
{
	while (list)
	{
		print_token(list);
		list = list->next;
	}
}

void		cmp_token_lists(t_token *list1, t_token *list2)
{
	while (list1 && list2)
	{
		if ((list1->type != list2->type) || \
			(list1->subtype != list2->subtype) || \
//			ft_strcmp(list1->data, list2->data) || 
			ft_strcmp(list1->match, list2->match))
		{
			ft_putstr("\033[32m");
			print_token(list1);
			ft_putstr("\033[31m");
			print_token(list2);
			ft_putstr("\033[0m");
		}
		list1 = list1->next;
		list2 = list2->next;
	}
	if (list1 || list2)
	{
		ft_putstr("\033[31m\none of lists is not over!\n");
		if (list1)
		{
			ft_putstr("\033[32m");
			print_token_list(list1);
		}
		if (list2)
		{
			ft_putstr("\033[32m");
			print_token_list(list2);
		}
		ft_putstr("\033[0m");
	}
}

void		go_42(void)
{
	char			*input;
	t_syntax_tree	*tree;
	t_token			*tokens;
	t_token			*tokens1;

	while (1)
	{
		if ((input = ft_readline()))
		{
			tokens1 = get_token_list(input ? input : "");
			tokens = token_scan_string(input ? input : "");
			cmp_token_lists(tokens, tokens1);
//            print_token_list(tokens);
//            print_token_list(tokens1);
			ft_find_quotes(&tokens, &input);
			parser_init_symbol(tokens);
			tree = syntax_exprl();
			parser_simplify(&tree);
			parser_simplify(&tree);
			write(1, "\n", 1);
			ft_preprocessing(tree);
			ft_free_syntax_tree(tree);
			token_free_all(tokens);
			token_free_all(tokens1);
			free(input);
		}
		else
			write(1, "\n", 1);
	}
}

int			main(int argc, const char *const argv[], const char *const envp[])
{
	(void)argc;
	(void)argv;
	if (argc > 1)
	{
		ft_putstr_fd("wtf?: non-interactive mode is not \
supported yet\n", 2);
		return (0);
	}
	init_42(envp);
	go_42();
	ft_free();
	return (0);
}
