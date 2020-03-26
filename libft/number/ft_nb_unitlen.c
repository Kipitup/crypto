/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_unitlen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 08:57:55 by fkante            #+#    #+#             */
/*   Updated: 2020/03/12 16:25:15 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_nb_unitlen(int nb)
{
	size_t		length;

	length = 0;
	if (nb <= 0)
		length++;
	nb = (int)ft_absolute(nb);
	while (nb != 0)
	{
		nb = nb / 10;
		length++;
	}
	return (length);
}
