/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_found_code_key.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 19:38:52 by alhelson          #+#    #+#             */
/*   Updated: 2017/01/18 22:23:28 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_select.h"
#include <unistd.h>
#include "ft_ori.h"

static int	ft_ret_for_27(char buffer[])
{
	if (buffer[1] == 91 && buffer[2] == 51)
		return (DELETE);
	else if (buffer[2] == 65)
		return (TOP);
	else if (buffer[2] == 66)
		return (BOTTOM);
	else if (buffer[2] == 67)
		return (RIGHT);
	else if (buffer[2] == 68)
		return (LEFT);
	else if (buffer[0] == 4)
		return (CTRLD);
	else if (buffer[1] == 0 && buffer[2] == 0)
		return (ESC);
	else
		return (BAD);
}

int			ft_found_code_key(void)
{
	char	buffer[3];

	ft_memset(buffer, 0, 3);
	read(0, buffer, 3);
	if (buffer[0] == 27)
		return (ft_ret_for_27(buffer));
	else if (buffer[0] == 32)
		return (SPACE);
	else if (buffer[0] == 10)
		return (ENTER);
	else if (buffer[0] == 127)
		return (BACKSPACE);
	else
		return (BAD);
}
