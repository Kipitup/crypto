/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:37:24 by amartino          #+#    #+#             */
/*   Updated: 2020/03/12 13:40:01 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int64_t		ft_atol(const char *str)
{
	int			i;
	int			neg;
	uint64_t	tmp;

	tmp = 0;
	i = 0;
	neg = 1;
	while ((str[i] >= 8 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		neg = -neg;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		tmp = tmp * 10 + (uint64_t)(str[i] - '0');
		i++;
	}
	return ((int64_t)tmp * neg);
}
