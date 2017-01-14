#include "ft_ori.h"
#include "ft_select.h"

void	ft_term_clear(void)
{
	if (ft_applied_basic_capa_str("cl"))
		return ;
	ft_putstr_fd("* error: ft_term_clear\n", 2);
}
