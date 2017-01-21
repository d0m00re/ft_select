/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_one_line_display_is_valid.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 22:19:45 by alhelson          #+#    #+#             */
/*   Updated: 2017/01/18 22:20:47 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_ori.h"

static int	ft_size_total(t_tlist *tlist)
{
	int		size;
	int		c;

	if (!tlist)
		return (0);
	c = 0;
	size = 0;
	while (c < tlist->nb_elem)
	{
		size += tlist->telem[c].size + 1;
		c++;
	}
	return (size - 1);
}

static int	ft_size_word_max(t_tlist *tlist)
{
	int size_max;
	int count;

	size_max = 0;
	count = 0;
	while (count < tlist->nb_elem)
	{
		if (size_max < tlist->telem[count].size)
			size_max = tlist->telem[count].size;
		count++;
	}
	return (size_max);
}

/*
** 1 : display one line (size line < size line term)
** 2 : display col (nb_word < size_term)
** 0 : error
*/
int			ft_one_line_display_is_valid(t_tlist *tlist)
{
	int size_total_one_line;
	int max_size_one_word;

	size_total_one_line = ft_size_total(tlist);
	max_size_one_word = ft_size_word_max(tlist);
	if (size_total_one_line <= ft_term_get_weight())
		return (1);
	else if (tlist->nb_elem < ft_term_get_height() && max_size_one_word <= ft_term_get_weight())
		return (2);
	return (0);
}
