/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term_get_height.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 22:24:42 by alhelson          #+#    #+#             */
/*   Updated: 2017/01/18 22:24:44 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>

int	ft_term_get_height(void)
{
	return (tgetnum("li"));
}
