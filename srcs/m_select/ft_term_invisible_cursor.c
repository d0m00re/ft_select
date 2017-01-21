/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term_invisible_cursor.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 22:31:04 by alhelson          #+#    #+#             */
/*   Updated: 2017/01/18 22:31:19 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include "ft_ori.h"

void	ft_term_invisible_cursor(void)
{
	if (!ft_applied_basic_capa_str("vi"))
		ft_putstr_fd("*error: ft_term_invisible_cursor.\n", 2);
}
