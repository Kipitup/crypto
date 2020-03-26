/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:02:08 by fkante            #+#    #+#             */
/*   Updated: 2019/04/20 17:03:38 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if ((((const unsigned char*)s1)[i]) != (((const unsigned char*)s2)[i]))
		{
			return ((((const unsigned char*)s1)[i])
					- (((const unsigned char*)s2)[i]));
		}
		i++;
	}
	return (0);
}
