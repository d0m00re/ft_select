#include <term.h>
#include <termios.h>
#include <stdlib.h>
#include "ft_select.h"

int	ft_reset_term(void)
{
	struct termios term;

	if (tcgetattr(0, &term) == -1) // recuperer les info dans la structure termios
		return (-1);
	term.c_lflag = (ICANON | ECHO);
	if (tcsetattr(0, TCSANOW, &term) == -1)
		return (-1);
	ft_applied_basic_capa_str("vs");
	return (1);
}
