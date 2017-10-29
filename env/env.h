
#ifndef __FT_ENV_H
# define __FT_ENV_H

# include <stdlib.h>
# include <string.h>

# include "../libft/libft.h"

char			**env_init(const char **environ);
void			env_set(char ***env, const char *key, const char *value);
char			*env_get(char **env, const char *key);
void			env_remove(char ***env, const char *key);

#endif
