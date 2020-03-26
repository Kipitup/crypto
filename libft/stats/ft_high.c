/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_high.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 12:01:11 by amartino          #+#    #+#             */
/*   Updated: 2019/11/30 16:27:09 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int32_t		ft_high(int32_t *tab, size_t size)
{
	int32_t		high;
	size_t		i;

	i = 0;
	high = tab[i];
	while (i < size)
	{
		if (high < tab[i])
			high = tab[i];
		i++;
	}
	return (high);
}
