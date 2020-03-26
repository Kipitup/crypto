/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow_positive.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 11:37:04 by amartino          #+#    #+#             */
/*   Updated: 2020/01/24 11:53:35 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long	ft_pow_positive(unsigned long x, unsigned long exponent)
{
	unsigned long	i;
	unsigned long	tmp;

	i = 1;
	tmp = x;
	while (i < exponent)
	{
		x *= tmp;
		i++;
	}
	return (exponent == 0 ? 1 : x);
}
