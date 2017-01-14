#include "ft_ori.h"
#include "ft_select.h"

int main(int argc, char **argv)
{
	t_tlist *tlist;

	if (argc < 2)
		ft_putstr_fd("Usage: ./ft_select [...]", 2);
	tlist = ft_parse_argv_to_tlist(argc, argv);
	ft_tlist_del(&tlist);
	return (1);
}
