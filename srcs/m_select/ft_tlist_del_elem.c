/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tlist_del_elem.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 22:18:49 by alhelson          #+#    #+#             */
/*   Updated: 2017/01/18 22:18:51 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	ft_tlist_del_elem(t_tlist *tlist, int id)
{
	int c;

	if (!tlist || id >= tlist->nb_elem || id < 0 || tlist->nb_elem <= 0)
		return ;
	if (tlist->telem[id].name)
		free(tlist->telem[id].name);
	c = id;
	tlist->nb_elem -= 1;
	while (c < tlist->nb_elem)
	{
		tlist->telem[c] = tlist->telem[c + 1];
		c++;
	}
}
