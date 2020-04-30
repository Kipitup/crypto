/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seed.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 19:55:43 by ldevelle          #+#    #+#             */
/*   Updated: 2020/03/31 19:47:06 by ezalos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

intmax_t	ft_seed_string(const char *str, size_t len)
{
	intmax_t	seed;
	intmax_t	seedo;
	intmax_t	i;

	seed = 0;
	i = -1;
	while (++i < (intmax_t)len)
		seed += (intmax_t)str[i] * (i + 1);
	seedo = *str++;
	while (*str)
		seedo ^= *str++;
	return (seed * seedo);
}
