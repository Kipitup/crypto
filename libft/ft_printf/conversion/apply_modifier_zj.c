/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_modifier_zj.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 17:37:48 by fkante            #+#    #+#             */
/*   Updated: 2019/09/20 08:51:41 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int64_t		apply_modifier_zj(int64_t nbr_conv, uint32_t flag)
{
	if (flag & FLAG_Z)
	{
		if (flag & CONV_D || flag & CONV_I)
			return ((ssize_t)nbr_conv);
		else if (flag & CONV_O || flag & CONV_U
				|| flag & CONV_X || flag & CONV_X_MAJ)
			return ((size_t)nbr_conv);
	}
	if (flag & FLAG_J)
	{
		if (flag & CONV_D || flag & CONV_I)
			return ((intmax_t)nbr_conv);
		else if (flag & CONV_O || flag & CONV_U
				|| flag & CONV_X || flag & CONV_X_MAJ)
		{
			return ((uintmax_t)nbr_conv);
		}
	}
	return (nbr_conv);
}
