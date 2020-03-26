/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_high.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 12:01:11 by amartino          #+#    #+#             */
/*   Updated: 2020/03/12 14:41:47 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_get_high(int32_t *tab, size_t size)
{
	size_t		high;
	size_t		i;

	i = 0;
	high = 0;
	while (i < size)
	{
		if (tab[high] < tab[i])
			high = i;
		i++;
	}
	return (i);
}
