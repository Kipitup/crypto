/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 11:37:04 by amartino          #+#    #+#             */
/*   Updated: 2020/01/21 19:36:31 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_pow(double x, double exponent)
{
	double	i;
	double	tmp;
	int8_t	neg;

	i = 1;
	neg = 0;
	tmp = x;
	if (exponent < 0)
	{
		exponent *= -1;
		neg = 1;
	}
	while (i < exponent)
	{
		x *= tmp;
		i++;
	}
	if (neg == 0)
		return (exponent == 0 ? 1 : x);
	else
		return (exponent == 0 ? 1 : (1 / x));
}
