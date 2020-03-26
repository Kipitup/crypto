/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 12:01:11 by amartino          #+#    #+#             */
/*   Updated: 2019/11/25 13:21:12 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int32_t		ft_range(int32_t *tab, size_t size)
{
	int32_t		low;
	int32_t		high;
	size_t		i;

	i = 0;
	low = tab[i];
	high = tab[i];
	while (i < size)
	{
		if (low > tab[i])
			low = tab[i];
		if (high < tab[i])
			high = tab[i];
		i++;
	}
	return (high - low);
}
