/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seed.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 19:55:43 by ldevelle          #+#    #+#             */
/*   Updated: 2020/03/31 19:29:08 by ezalos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

intmax_t	ft_seed_string(const char *str, size_t len)
{
	intmax_t	seed;
	intmax_t	seedo;
	int			i;

	seed = 0;
	i = -1;
	while (++i < (int)len)
		seed += (int)str[i] * (i + 1);
	seedo = *str++;
	while (*str)
		seedo ^= *str++;
	return (seed * seedo);
}
