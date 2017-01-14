#include "ft_select.h"
#include "ft_ori.h"

void	ft_term_invisible_cursor(void)
{
	if (!ft_applied_basic_capa_str("vi"))
		ft_putstr_fd("*error: ft_term_invisible_cursor.\n", 2);
}
