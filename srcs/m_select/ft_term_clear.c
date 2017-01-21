/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 22:18:22 by alhelson          #+#    #+#             */
/*   Updated: 2017/01/18 22:18:27 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"
#include "ft_select.h"

void	ft_term_clear(void)
{
	if (ft_applied_basic_capa_str("cl"))
		return ;
	ft_putstr_fd("* error: ft_term_clear\n", 2);
}
