#include "ft_select.h"
#include "ft_ori.h"

static	void ft_manage_arrow_event(int id, int size_max, int *cursor)
{
	if (id == LEFT)
	{
		if ((*cursor) > 0)
			(*cursor)--;
		else
			(*cursor) = size_max - 1;
	}
	else if (id == RIGHT)
	{
		if ((*cursor) < size_max - 1)
			(*cursor)++;
		else
			(*cursor) = 0;
	}
}

static void	ft_manage_space_event(int id, t_tlist *tlist)
{
	if (tlist->telem[id].select == 0)
		tlist->telem[id].select = 1;
	else
		tlist->telem[id].select = 0;
}

static void	ft_manage_enter_event(int *id, t_tlist *tlist)
{
	ft_tlist_del_elem(tlist, *id);
	if (*id >= tlist->nb_elem)
		(*id)--;
}

int	ft_manage_keyboard_event(int id, t_tlist *tlist, int *cursor)
{
	if (id >= TOP && id <= LEFT)
		ft_manage_arrow_event(id, tlist->nb_elem, cursor);
	else if (id == SPACE)
		ft_manage_space_event(*cursor, tlist);
	else if (id == ENTER)
		ft_manage_enter_event(cursor, tlist);
	return (1);
}
