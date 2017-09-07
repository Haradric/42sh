#ifndef __FT_EXEC_PRIVATE_H
# define __FT_EXEC_PRIVATE_H

# include <sys/wait.h>
# include "ft_exec.h"
# include "ft_env.h"
// # include "ft_readline.h"
# include "ft_builtin.h"
# include "../libft/libft.h"

void			ft_exec_dup(t_proc *proc);
void			ft_exec_close_except(t_proc **all, t_proc *proc);
void			ft_exec_spawn(t_proc **all, t_proc *proc);
void			ft_exec_wait_all(t_proc **all);
int		ft_exec_standart(t_proc **proc);

#endif
