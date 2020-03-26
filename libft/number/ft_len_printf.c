/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_printf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 10:48:48 by fkante            #+#    #+#             */
/*   Updated: 2019/09/20 10:58:52 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "define_pf.h"

size_t		ft_len_printf(uint64_t value, uint64_t flag, size_t len)
{
	(void)value;
	if (len > 8 && ((flag & CONV_X && flag & FLAG_LL) || flag & FLAG_J))
		len = 16;
	else if (len > 8 && flag & CONV_X && ((flag & FLAG_J) != FLAG_J))
		len = 8;
	else if (len > 11 && flag & CONV_O)
		len = 11;
	return (len);
}
