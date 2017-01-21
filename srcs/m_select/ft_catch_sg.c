/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_catch_sg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 19:37:44 by alhelson          #+#    #+#             */
/*   Updated: 2017/01/18 19:37:57 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "ft_ori.h"
#include "ft_select.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <term.h>
#include <sys/ioctl.h>

t_tlist *g_tlist;
int *g_cursor;

void	ft_catch_sg(int id)
{
	char c;
	char *update;

	if (SIGWINCH == id)
	{
		ft_term_clear();
		if (!(update = getenv("TERM")))
			return ;
		tgetent(0, update);
		ft_tlist_s_display(g_tlist, *g_cursor);
	}
	else if (SIGTSTP == id)
	{
		if (isatty(1))
		{
                	c = 26;
			ioctl(0, TIOCSTI, &c);
			ft_reset_term();
			signal(SIGTSTP, SIG_DFL);
		}
	}
	else if (SIGCONT == id)
	{
		ft_init_term();
		ft_term_invisible_cursor();
		ft_term_clear();
		signal(SIGTSTP, &ft_catch_sg);
		if (!(update = getenv("TERM")))
			return ;
		tgetent(0, update);
		ft_tlist_s_display(g_tlist, *g_cursor);
	}
}
