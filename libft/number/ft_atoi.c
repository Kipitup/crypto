/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 17:23:59 by fkante            #+#    #+#             */
/*   Updated: 2020/03/12 11:53:30 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
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
	if (tmp > LONG_MAX)
		return (neg == -1 ? 0 : -1);
	return ((int)tmp * neg);
}
