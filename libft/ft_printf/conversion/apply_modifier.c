/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_modifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 17:33:08 by fkante            #+#    #+#             */
/*   Updated: 2019/09/20 09:51:51 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int64_t		apply_modifier_di(int64_t nbr_conv, uint32_t flag)
{
	if (flag & FLAG_HH)
		nbr_conv = (int8_t)nbr_conv;
	else if (flag & FLAG_H)
		nbr_conv = (int16_t)nbr_conv;
	else if (flag & FLAG_L)
		nbr_conv = (int64_t)nbr_conv;
	else if (flag & FLAG_LL)
		nbr_conv = (int64_t)nbr_conv;
	else
		nbr_conv = (int32_t)nbr_conv;
	return (nbr_conv);
}

uint64_t	apply_modifier_oxx_maj(int64_t nbr_conv, uint32_t flag)
{
	if (flag & FLAG_HH)
		nbr_conv = (uint8_t)nbr_conv;
	else if (flag & FLAG_H)
		nbr_conv = (uint16_t)nbr_conv;
	else if (flag & FLAG_L)
		nbr_conv = (uint64_t)nbr_conv;
	else if (flag & FLAG_LL)
		nbr_conv = (uint64_t)nbr_conv;
	else
		nbr_conv = (uint32_t)nbr_conv;
	return (nbr_conv);
}

uint64_t	apply_modifier_u(uint64_t nbr_conv, uint32_t flag)
{
	if (flag & FLAG_HH)
		nbr_conv = (uint8_t)nbr_conv;
	else if (flag & FLAG_H)
		nbr_conv = (uint16_t)nbr_conv;
	else if (flag & FLAG_L)
		nbr_conv = (uint64_t)nbr_conv;
	else if (flag & FLAG_LL)
		nbr_conv = (uint64_t)nbr_conv;
	else
		nbr_conv = (uint32_t)nbr_conv;
	return (nbr_conv);
}

uint64_t	apply_modifier_p(uint64_t address, uint64_t flag)
{
	if (flag & FLAG_HH)
		address = (uint64_t)address;
	else if (flag & FLAG_H)
		address = (uint64_t)address;
	else if (flag & FLAG_L)
		address = (unsigned long)address;
	else if (flag & FLAG_LL)
		address = (uint64_t)address;
	else
		address = (uint64_t)address;
	return (address);
}

uint64_t	apply_modifier_s(uint64_t str, uint64_t flag)
{
	if (flag & FLAG_HH)
		str = (uint64_t)str;
	else if (flag & FLAG_H)
		str = (uint64_t)str;
	else if (flag & FLAG_L)
		str = 0;
	else if (flag & FLAG_LL)
		str = (uint64_t)str;
	return (str);
}
