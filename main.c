#include "ft_ori.h"
#include "ft_select.h"

void	test_display(t_tlist *tlist)
{
	ft_tlist_s_display(tlist, 5);
	tlist->telem[0].select = 1;
	tlist->telem[2].select = 1;
	ft_tlist_s_display(tlist, 2);
}

int main(int argc, char **argv)
{
	int cursor;
	int ret;
	t_tlist *tlist;

	cursor = 0;
	if (argc < 2)
		ft_putstr_fd("Usage: ./ft_select [...]\n", 2);
	ft_init_term();
	tlist = ft_parse_argv_to_tlist(argc, argv);
	//test_display(tlist);
	ft_term_invisible_cursor();
	while (1)
	{
		ft_term_clear();
		ft_tlist_s_display(tlist, cursor);
		ret = ft_found_code_key();
		ft_manage_keyboard_event(ret, tlist, &cursor);
	}
	ft_tlist_del(&tlist);
	return (1);
}
