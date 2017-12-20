
#ifndef FT_HASH_TABLE_H
# define FT_HASH_TABLE_H

# include <stdlib.h>
# include <unistd.h>
# include <dirent.h>

# include "../shell.h"

# define HASH_SIZE 1000

typedef struct		s_hash
{
	char			*command;
	char			*filename;
	struct s_hash	*next;
}					t_hash;

t_hash				**ft_hash_table(char **env);
void				ft_hash_set(t_hash **table, char *command,
								char *filename);
char				*ft_hash_get(t_hash **table, char *command);
void				ft_hash_remove(t_hash **table, char *command);
void				free_hash_table(t_hash ***table);

#endif
