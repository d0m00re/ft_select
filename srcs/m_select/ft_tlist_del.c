#include "ft_select.h"
#include <stdlib.h>
#include "ft_ori.h"

void	ft_tlist_del(t_tlist **tlist)
{
	int c;

	if (!tlist || !(*tlist))
		return ;
	c = 0;
	while (c < (*tlist)->nb_elem)
	{
		free((*tlist)->telem[c].name);
		c++;
	}
	free((*tlist)->telem);
	free((*tlist));
	*tlist = 0;
}
