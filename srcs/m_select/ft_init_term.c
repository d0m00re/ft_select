/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_term.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 19:39:08 by alhelson          #+#    #+#             */
/*   Updated: 2017/01/18 22:30:35 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <termios.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/*
 * tgetent : load routine for the entry name
 * tcgetattr : recuperer la struvture termios
 * ICANON : terminal en mode canonique
 * ECHO : les touche tape ne s affiche plus
*/
int			ft_init_term(void)
{
	char	*name_term;
	struct	termios term;

	if (!(name_term = getenv("TERM")))
		return (-1);
	if (!tgetent(NULL, name_term)) // load routine the entru for name
		return (-1);
	if (tcgetattr(0, &term) == -1) // recuperer les info dans la structure termios
		return (-1);
	term.c_lflag &= ~(ICANON); // terminal en mode canonique
	term.c_lflag &= ~(ECHO); // les touches tape ne s affiche plus
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (-1);
	return (1);
}
