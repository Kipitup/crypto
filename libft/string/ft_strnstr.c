/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 10:35:13 by fkante            #+#    #+#             */
/*   Updated: 2019/04/25 10:29:14 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *pil, const char *need, size_t len)
{
	size_t i;

	if (*need == '\0')
		return ((char*)pil);
	if (len == 0)
		return (NULL);
	while (len > 0 && *pil)
	{
		i = 0;
		while (pil[i] == need[i] && i < len && pil[i] && need[i])
			i++;
		if (!need[i])
			return ((char*)pil);
		len--;
		pil++;
	}
	return (NULL);
}
