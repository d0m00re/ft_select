/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_applied_basic_capa_str.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 19:37:27 by alhelson          #+#    #+#             */
/*   Updated: 2017/01/18 19:37:39 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"
#include <term.h>

int		ft_applied_basic_capa_str(char *str)
{
	char *tmp;

	if (!str)
		return (0);
	if (!(tmp = tgetstr(str, 0)))
		return (0);
	ft_putstr_fd(tmp, 0);
	return (1);
}
