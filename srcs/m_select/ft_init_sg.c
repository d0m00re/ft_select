/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_sg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 19:38:58 by alhelson          #+#    #+#             */
/*   Updated: 2017/01/18 22:26:21 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "ft_select.h"
#include <unistd.h>
#include <stdlib.h>

t_tlist	*g_tlist;
int		*g_cursor;

static void	ft_all_catch(int v)
{
	ft_reset_term();
//	signal (v, SIG_DFL);
	exit (1);
}

void	ft_init_sg(t_tlist **tlist, int *cursor)
{
	int c;
	g_tlist = *tlist;
	g_cursor = cursor;

	c = 0;
	while (c < 45)
	{
		signal (c, &ft_all_catch);
		c++;
	}
	signal(SIGWINCH, &ft_catch_sg);
	signal(SIGTSTP, &ft_catch_sg);
	signal(SIGCONT, &ft_catch_sg);
}
