#include "ft_ori.h"
#include "ft_select.h"

void	ft_term_begin_soulign(void)
{
	if (ft_applied_basic_capa_str("us"))
		return ;
	ft_putstr_fd("* error: ft_begin_soulign\n", 2);
}
