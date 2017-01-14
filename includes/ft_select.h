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

enum e_touch{BAD, TOP, BOTTOM, RIGHT, LEFT, ENTER, CTRLD, SPACE};

t_tlist *ft_parse_argv_to_tlist(int argc, char **argv);

void	ft_tlist_del_elem(t_tlist *tlist, int id);

void	ft_tlist_del(t_tlist **tlist);

void	ft_tlist_display(t_tlist *tlist);

void	ft_tlist_s_display(t_tlist *tlist, int cursor);

int	ft_applied_basic_capa_str(char *key);

int	ft_init_term(void);

void	ft_term_begin_soulign(void);

void	ft_term_end_soulign(void);

void	ft_term_invisible_cursor(void);

void	ft_term_clear(void);

/*
** found touch code
*/
int	ft_found_code_key(void);

int	ft_manage_keyboard_event(int id, t_tlist *tlist, int *cursor);
#endif
