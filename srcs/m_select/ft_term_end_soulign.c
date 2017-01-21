/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term_end_soulign.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 22:19:01 by alhelson          #+#    #+#             */
/*   Updated: 2017/01/18 22:19:02 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"
#include "ft_select.h"

void	ft_term_end_soulign(void)
{
	if (!ft_applied_basic_capa_str("ue"))
		ft_putstr_fd("* error: ft_begin_soulign\n", 2);
}
