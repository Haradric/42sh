
#include "ft_readline.h"
#include "ft_signals.h"

void			terminal_switch_mode(void)
{
	struct termios	termios;

	tcgetattr(2, &termios);
	termios.c_lflag = (termios.c_lflag ^ ICANON) ^ ECHO;
	tcsetattr(2, TCSANOW, &termios);
}

char			*input_get(void)
{
	char	*line;

	line = NULL;
	ft_signals_input();
	terminal_switch_mode();
	ft_putstr(g_prompt);
	ft_get_line(&line, &g_history);
	terminal_switch_mode();
	ft_signals();
	return (line);
}
