#include "ft_select.h"
#include "ft_ori.h"

void	ft_tlist_display(t_tlist *tlist)
{
	int c;

	if (!tlist || tlist->nb_elem < 1 || !(tlist->telem))
		return ;
	c = 0;
	while (c < tlist->nb_elem)
	{
		ft_putstr(tlist->telem[c].name);
		ft_putstr(" ");
		c++;
	}
	ft_putstr("\n");
}
