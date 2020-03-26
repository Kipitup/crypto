/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_low.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 12:01:11 by amartino          #+#    #+#             */
/*   Updated: 2020/03/12 14:41:37 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_get_low(int32_t *tab, size_t size)
{
	size_t		low;
	size_t		i;

	i = 0;
	low = 0;
	while (i < size)
	{
		if (tab[low] > tab[i])
			low = i;
		i++;
	}
	return (low);
}
