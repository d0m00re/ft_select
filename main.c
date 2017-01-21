/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 14:07:09 by alhelson          #+#    #+#             */
/*   Updated: 2017/01/19 14:22:30 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"
#include "ft_select.h"

static char	*ft_manage_select(t_tlist *tlist, int *cursor)
{
	int		ret;
	char	*str;

	ret = 0;
	str = 0;
	while (ret != ESC && ret != ENTER && tlist->nb_elem > 0)
	{
		ft_term_clear();
		ft_tlist_s_display(tlist, *cursor);
		ret = ft_found_code_key();
		if (ret != ESC && ret != ENTER)
			ft_manage_keyboard_event(ret, tlist, cursor);
		if (tlist->nb_elem == 0)
			ft_term_clear();
	}
	if (ret == ENTER && tlist->nb_elem > 0)
		str = ft_tlist_parse_select_str(tlist);
	return (str);
}

static char	*ft_select(int argc, char **argv)
{
	t_tlist	*tlist;
	char	*str;
	int		cursor;

	str = 0;
	cursor = 0;
	if (argc < 2)
	{
		ft_putstr_fd("Usage: ./ft_select [...]\n", 2);
		return (0);
	}
	ft_init_term();
	tlist = ft_parse_argv_to_tlist(argc, argv);
	ft_init_sg(&tlist, &cursor);
	ft_term_invisible_cursor();
	str = ft_manage_select(tlist, &cursor);
	ft_tlist_del(&tlist);
	ft_reset_term();
	return (str);
}

int			main(int argc, char **argv)
{
	char	*str;

	str = ft_select(argc, argv);
	if (str)
		ft_putendl(str);
	ft_strdel(&str);
	return (0);
}
