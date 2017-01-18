#include "ft_select.h"
#include <stdio.h>
#include <stdlib.h>

static int	ft_size_total(t_tlist *tlist)
{
	int size;
	int c;

	if (!tlist)
		return (0);
	c = 0;
	size = 0;
	while (c < tlist->nb_elem)
	{
		size += tlist->telem[c].size + 1;
		c++;
	}
	return (size - 1);
}

/*
** 1 : line display valid
*/
int	ft_one_line_display_is_valid(t_tlist *tlist)
{
	if ((ft_size_total(tlist)) < (ft_term_get_weight() * ft_term_get_height()))
		return (1);
	return (0);
}
