/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_modifier_f.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 17:50:50 by fkante            #+#    #+#             */
/*   Updated: 2019/09/18 19:48:40 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long double	apply_modifier_f(long double nbr, int32_t flag)
{
	if (flag & FLAG_L)
		return (nbr);
	else if (flag & FLAG_L_MAJ)
		nbr = (long double)nbr;
	else
		nbr = (float)nbr;
	return (nbr);
}
