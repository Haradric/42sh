
#include "ft_history.h"

void	history_free(t_his **list)
{
	t_his	*tmp;

	while (*list)
	{
		tmp = *list;
		*list = (*list)->next;
		if (tmp->tmp)
			free(tmp->tmp);
		if (tmp->data)
			free(tmp->data);
		free(tmp);
	}
}
