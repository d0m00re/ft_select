#include "ft_ori.h"
#include "ft_select.h"
#include <stdlib.h>

t_tlist *ft_parse_argv_to_tlist(int argc, char **argv)
{
	int c;
	t_tlist *tlist;

	if (!(tlist = malloc(sizeof(t_tlist))))
		return (0);
	if (!(tlist->telem = malloc(sizeof(t_telem) * (argc - 1))))
		return (0);
	tlist->nb_elem = argc - 1;
	c = 1;
	while (c < argc)
	{
		if (!(tlist->telem[c - 1].name = ft_strdup(argv[c])))
			return (0);
		tlist->telem[c - 1].size = ft_strlen(argv[c]);
		tlist->telem[c - 1].select = 0;
		c++;
	}
	return (tlist);
}
