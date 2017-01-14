#include <term.h>
#include <termios.h>
#include <stdlib.h>
#include <curses.h>

int	ft_init_term(void)
{
	char *name_term;
	struct termios term;

	if (!(name_term = getenv("TERM")))
		return (-1);
	if (!tgetent(NULL, name_term)) // load routine the entru for name
		return (-1);
	if (tcgetattr(0, &term) == -1) // recuperer les info dans la structure termios
		return (-1);
	term.c_lflag &= ~(ICANON); // terminal en mode canonique
	term.c_lflag &= ~(ECHO); // les touches tape ne s affiche plus
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (-1);
	return (1);
}
