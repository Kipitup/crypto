/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 10:09:31 by fkante            #+#    #+#             */
/*   Updated: 2020/03/12 16:21:25 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Locate the last occurence of c
*/
char	*ft_strrchr(const char *s, int c)
{
	ssize_t	i;

	if (c == '\0')
		return ((char*)s + ft_strlen(s));
	i = (size_t)ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
		{
			return ((char*)s + i);
		}
		i--;
	}
	return (NULL);
}
