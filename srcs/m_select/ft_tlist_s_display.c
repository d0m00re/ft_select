#include "ft_select.h"
#include "ft_ori.h"

void ft_tlist_s_display(t_tlist *tlist, int cursor)
{
	int c;

	if (!tlist)
		return ;
	c = 0;
	while (c < tlist->nb_elem)
	{
		if (tlist->telem[c].select)
			ft_applied_basic_capa_str("mr");
		if (cursor == c)
			ft_term_begin_soulign();
		ft_putstr(tlist->telem[c].name);
		if (cursor == c || tlist->telem[c].select)
			ft_applied_basic_capa_str("me");
		c++;
		if (c < tlist->nb_elem)
			ft_putchar(' ');
	}
	ft_putchar('\n');
}
