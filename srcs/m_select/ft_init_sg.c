#include <signal.h>
#include "ft_select.h"

t_tlist *g_tlist;
int     *g_cursor;


void	ft_init_sg(t_tlist **tlist, int *cursor)
{
	g_tlist = *tlist;
	g_cursor = cursor;
	signal (SIGWINCH, &ft_catch_sg);
	signal (SIGTSTP, &ft_catch_sg);
	signal (SIGCONT, &ft_catch_sg);
}
