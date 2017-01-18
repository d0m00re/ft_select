#include "ft_select.h"
#include "ft_ori.h"
#include <stdlib.h>

static int	ft_total_size(t_tlist *tlist)
{
	int size;
	int c;

	c = 0;
	size = 0;
	while (c < tlist->nb_elem)
	{
		if (tlist->telem[c].select)
			size += (tlist->telem[c].size + 1);
		c++;
	}
	return (size);
}

char	*ft_tlist_parse_select_str(t_tlist *tlist)
{
	int c;
	int total_size;
	char *str;

	c = 0;
	if ((total_size = ft_total_size(tlist)) < 1)
		return (0);
	if (!(str = malloc(sizeof(char) * total_size)))
		return (0);
	ft_memset(str, 0, total_size);
	while (c < tlist->nb_elem)
	{
		if (tlist->telem[c].select)
		{
			ft_strcat(str, tlist->telem[c].name);
			ft_strcat(str, " ");
		}
		c++;
	}
	str[ft_strlen(str) - 1] = 0;
	return (str);
}
