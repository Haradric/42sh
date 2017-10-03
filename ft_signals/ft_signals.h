/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 17:00:51 by mbraslav          #+#    #+#             */
/*   Updated: 2017/09/28 17:00:53 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SIGNALS_H
# define FT_SIGNALS_H

# include <signal.h>
# include <sys/ioctl.h>
# include "../libft/libft.h"

extern int	g_parent;
extern char	*g_promt;
extern char	*g_lft;
extern char	*g_rgt;

void		ft_signals(void);
void		ft_signals_input(void);
void		ft_terminal_set(void);

#endif
