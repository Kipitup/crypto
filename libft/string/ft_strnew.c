/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 09:29:03 by fkante            #+#    #+#             */
/*   Updated: 2019/04/26 18:00:05 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*tmp;

	if (!(tmp = ft_memalloc(size + 1)))
		return (NULL);
	while (size > 0)
	{
		tmp[size] = '\0';
		size--;
	}
	tmp[0] = '\0';
	return (tmp);
}
