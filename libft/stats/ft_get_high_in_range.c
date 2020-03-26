/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_high_in_range.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 15:55:56 by fkante            #+#    #+#             */
/*   Updated: 2020/03/12 14:41:17 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_get_high_in_range(int32_t *tab, size_t start, size_t end)
{
	size_t		high;

	high = start;
	while (start < end)
	{
		if (tab[high] < tab[start])
			high = start;
		start++;
	}
	return (high);
}
