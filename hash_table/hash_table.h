
#ifndef HASH_TABLE_H
# define HASH_TABLE_H

# include <stdlib.h>
# include <dirent.h>

# include "../shell.h"

# define HASH_SIZE 1000

typedef struct		s_hash
{
	char			*command;
	char			*filename;
	struct s_hash	*next;
}					t_hash;

t_hash				**hash_table_init(char **env);
void				hash_set(t_hash **table, char *command,
								char *filename);
char				*hash_get(t_hash **table, char *command);
void				hash_remove(t_hash **table, char *command);
void				hash_table_free(t_hash ***table);

#endif
