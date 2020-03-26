/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:56:50 by fkante            #+#    #+#             */
/*   Updated: 2020/03/04 09:49:48 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *tmp;

	if (size <= 0)
		return (NULL);
	if ((tmp = malloc(size)) == NULL)
		return (NULL);
	ft_bzero(tmp, size);
	return (tmp);
}
