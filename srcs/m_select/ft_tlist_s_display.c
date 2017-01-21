/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tlist_s_display.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 22:17:52 by alhelson          #+#    #+#             */
/*   Updated: 2017/01/18 22:18:03 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include "ft_ori.h"

/* retour a la ligne a add */

void	ft_tlist_s_display(t_tlist *tlist, int cursor)
{
	int c;
	int ret;

	if (!tlist || !(ret = ft_one_line_display_is_valid(tlist)))
		return ;
	c = 0;
	while (c < tlist->nb_elem)
	{
		if (tlist->telem[c].select)
			ft_applied_basic_capa_str("mr");
		if (cursor == c)
			ft_term_begin_soulign();
		ft_putstr_fd(tlist->telem[c].name, 0);
		if (cursor == c || tlist->telem[c].select)
			ft_applied_basic_capa_str("me");
		c++;
		if (c < tlist->nb_elem)
		{
			if (ret == 1)
				ft_putchar_fd(' ', 0);
			else
				ft_putchar_fd('\n', 0);
		}
	}
	ft_putchar('\n');
}
