/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <a.martino@sutdent.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 17:49:49 by amartino          #+#    #+#             */
/*   Updated: 2020/03/07 18:01:02 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint8_t		ft_is_prime(uint32_t nb)
{
	uint32_t	divider;

	divider = 2;
	if (nb < 2)
		return (FALSE);
	while (divider < nb)
	{
		if ((nb % divider) == 0)
			return (FALSE);
		divider++;
	}
	return (TRUE);
}
