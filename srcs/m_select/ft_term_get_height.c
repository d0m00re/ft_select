#include <term.h>

int	ft_term_get_height(void)
{
	return (tgetnum("co"));
}
