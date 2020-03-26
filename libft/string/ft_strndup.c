/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 12:12:45 by fkante            #+#    #+#             */
/*   Updated: 2020/01/15 12:16:25 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *src, size_t size)
{
	char	*dst;

	if (size == 0)
		return (NULL);
	if (!(dst = (char *)ft_memalloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_strncpy(dst, src, size);
	return (dst);
}
