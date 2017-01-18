#include <term.h>

int	ft_term_get_weight(void)
{
	return (tgetnum("li"));
}
