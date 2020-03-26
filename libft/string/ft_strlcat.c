/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:21:32 by fkante            #+#    #+#             */
/*   Updated: 2020/03/12 12:17:45 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen_len(size_t size, const char *s)
{
	size_t i;

	i = 0;
	while (i <= size)
	{
		if (s[i++] == '\0')
			return (i - 1);
	}
	return (size);
}

size_t			ft_strlcat(char *s1, const char *s2, size_t size)
{
	size_t size_s1;
	size_t size_s2;

	size_s1 = ft_strlen_len(size, (const char*)s1);
	size_s2 = ft_strlen(s2);
	if (size - size_s1 > 1)
	{
		ft_strncpy(s1 + size_s1, s2, size - size_s1);
		s1[size - 1] = '\0';
	}
	return (size_s1 + size_s2);
}
