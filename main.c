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
#include "hash_table.h"

#include "ft_history.h"
#include "ft_signals.h"
#include "ft_preprocessing.h"

char		**g_env;
t_hash		**g_table;

char		*g_prompt;
t_his		*g_history;
t_token		*g_prev_tok;
t_token		*g_curr_sym;
t_token		*g_next_sym;

int			g_parent;
char		*g_lft;
char		*g_rgt;

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
		g_prompt = ("bquote> ");
		return (1);
	}
	if (t->subtype == ST_DQUOTE_EOF)
	{
		g_prompt = ("dquote> ");
		return (1);
	}
	if (t->subtype == ST_QUOTE_EOF)
	{
		g_prompt = ("quote> ");
		return (1);
	}
	return (0);
}

void		ft_find_quotes(t_token **tokens, char **cmd)
{
	char	*oldprompt;

	oldprompt = g_prompt;
	while (unclosed_quote(*tokens, 0))
	{
		write(1, "\n", 1);
		free_token_list(*tokens);
		(*cmd) = ft_join_quote(*cmd, input_get());
		(*tokens) = get_token_list((*cmd) ? (*cmd) : "");
	}
	g_prompt = oldprompt;
}

void		go_42(void)
{
	char			*input;
	t_syntax_tree	*tree;
	t_token			*tokens;

	while (1)
	{
		if ((input = input_get()))
		{
			tokens = get_token_list(input ? input : "");
			ft_find_quotes(&tokens, &input);
			parser_init_symbol(tokens);
			tree = syntax_exprl();
			parser_simplify(&tree);
			parser_simplify(&tree);
			write(1, "\n", 1);
			ft_preprocessing(tree);
			ft_free_syntax_tree(tree);
			free_token_list(tokens);
			free(input);
		}
		else
			write(1, "\n", 1);
	}
}

static void	shell_init(const char **envp)
{
	char	*shlvl_str;

	g_env = env_init(envp);
	g_table = hash_table_init((char **)envp);
	g_prompt = ft_strjoin(env_get(g_env, "USER"), " > ");
	env_set(&g_env, "PROMPT", g_prompt);
	env_set(&g_env, "SHELL", "42sh");
	if ((shlvl_str = env_get(g_env, "SHLVL")))
	{
		shlvl_str = ft_itoa(ft_atoi(shlvl_str) + 1);
		env_set(&g_env, "SHLVL", shlvl_str);
		free(shlvl_str);
	}
	else
		env_set(&g_env, "SHLVL", "1");
	history_file_restore("~/.42sh_history");
	g_parent = 1;
	ft_signals();
}

int			main(int argc, const char **argv, const char **envp)
{
	(void)argc;
	(void)argv;
	sleep(1);
	if (argc > 1)
		terminate("42sh:", "non-interactive mode is not supported yet");
	shell_init(envp);
	go_42();
	hash_table_free(&g_table);
	history_free(&g_history);
	return (0);
}
