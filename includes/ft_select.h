#ifndef FT_SELECT_H
# define FT_SELECT_H

typedef struct	s_telem
{
	char	*name;
	int size;
	int select;
} t_telem;

typedef struct s_tlist
{
	t_telem *telem;
	int	nb_elem;
} t_tlist;

t_tlist *ft_parse_argv_to_tlist(int argc, char **argv);

void	ft_tlist_del(t_tlist **tlist);

int	ft_init_term(void);

#endif
