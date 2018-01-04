/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_to_history.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 13:51:02 by olyuboch          #+#    #+#             */
/*   Updated: 2017/10/01 15:58:09 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

void	ft_add_next(t_his **his)
{
	t_his	*next;

	if (!(next = (t_his *)malloc(sizeof(t_his))))
		return ;
	next->data = NULL;
	next->tmp = NULL;
	next->next = NULL;
	next->prev = (*his);
	(*his)->next = next;
}

void	ft_add_first(t_his **his, char *line)
{
	t_his	*new;

	if (!(new = (t_his *)malloc(sizeof(t_his))))
		return ;
	new->data = ft_strdup(line);
	new->tmp = NULL;
	new->next = NULL;
	new->prev = NULL;
	(*his) = new;
	ft_add_next(his);
}

void	ft_history_down(t_his **his)
{
	if ((*his))
	{
		while ((*his)->next)
			(*his) = (*his)->next;
	}
}

//static t_his	*new_entry(const char *data)
//{
//	t_his	*entry;
//
//	if (!(entry = ft_memalloc(sizeof(t_his))))
//		return (NULL);
//	entry->data = ft_strdup(data);
//	return (entry);
//}

void	history_add(t_his **his, char *line)
{
	if (!(*his))
		ft_add_first(his, line);
	else
	{
		ft_history_down(his);
		(*his)->data = ft_strdup(line);
		ft_add_next(his);
	}
	ft_history_down(his);
}
