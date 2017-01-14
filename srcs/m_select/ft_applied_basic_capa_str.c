#include "ft_ori.h"
#include <term.h>

int	ft_applied_basic_capa_str(char *str)
{
	char *tmp;

	if (!str)
		return (0);
	if (!(tmp = tgetstr(str, 0)))
		return (0);
	ft_putstr(tmp);
	return (1);
}
