/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:16:40 by fkante            #+#    #+#             */
/*   Updated: 2019/04/21 16:28:18 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t size_s1;

	i = 0;
	size_s1 = 0;
	while (s1[size_s1])
		size_s1++;
	while (i < n && s2[i])
	{
		s1[size_s1] = s2[i];
		size_s1++;
		i++;
	}
	s1[size_s1] = '\0';
	return (s1);
}
