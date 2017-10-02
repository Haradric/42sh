#include "shell.h"

char	*g_promt;
t_his	*g_history;
t_hash	**g_table;
t_token	*g_prev_tok;
t_token	*g_curr_sym;
t_token	*g_next_sym;
char	**g_env_g;
char	**g_env_l;
int		g_parent;
char	*g_lft;
char	*g_rgt;

void	init_42(const char *const envp[])
{
	char	*shlvl_str;

	g_parent = 1;
	g_table = ft_hash_table((char **)envp);
	g_env_g = ft_env_init(envp);
	g_history = NULL;
	ft_env_set(&g_env_g, "SHELL", "42sh");
	if ((shlvl_str = ft_env_get(g_env_g, "SHLVL")))
	{
		shlvl_str = ft_itoa(ft_atoi(shlvl_str) + 1);
		ft_env_set(&g_env_g, "SHLVL", shlvl_str);
		free(shlvl_str);
	}
	g_env_l = malloc(sizeof(char *) * 2);
	g_env_l[0] = NULL;
	ft_signals();
}

int 	unclosed_quote(t_token *t, int i)
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

char	*ft_join_quote(char *a, char *b)
{
	char *res;

	res = malloc(strlen(a) + 1 + strlen(b ?: "") + 1);
	strcpy(res, a);
	strcat(res, "\n");
	strcat(res, b ?: "");
	free(a);
	free(b);
	return (res);
}

void	ft_find_quotes(t_token **tokens, char **cmd)
{
	char	*oldpromt;

	oldpromt = g_promt;
	while (unclosed_quote(*tokens, 0))
	{
		write(1, "\n", 1);
		token_free_all(*tokens);
		(*cmd) = ft_join_quote(*cmd, ft_readline());
		(*tokens) = token_scan_string((*cmd) ?: "");
	}
	g_promt = oldpromt;
}

void	go_42(void)
{
	char			*cmd;
	t_syntax_tree	*tree;
	t_token			*tokens;

	while (1)
	{
		if ((cmd = ft_readline()))
		{
			tokens = token_scan_string(cmd ?: "");
			ft_find_quotes(&tokens, &cmd);
			parser_init_symbol(tokens);
			tree = syntax_exprl();
			parser_simplify(&tree);
			parser_simplify(&tree);
			write(1, "\n", 1);
			// ft_tree_print(tree, 0);
			ft_preprocessing(tree);
			ft_free_syntax_tree(tree);
			token_free_all(tokens);
			free(cmd);
		}
		else
			write(1, "\n", 1);
	}
}

int		main(int argc, const char *const argv[], const char *const envp[])
{
	(void)argc;
	(void)argv;
	init_42(envp);
	ft_history_upload();
	go_42();
	ft_free();
	return (0);
}
