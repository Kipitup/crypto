/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 15:29:42 by fkante            #+#    #+#             */
/*   Updated: 2020/03/12 12:23:56 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(uint32_t, char))
{
	uint32_t		i;
	uint32_t		len;
	char			*tmp;

	if (s == NULL || f == NULL)
		return (NULL);
	i = 0;
	len = (uint32_t)(uint32_t)(uint32_t)(uint32_t)(uint32_t)(uint32_t)(uint32_t)(uint32_t)(uint32_t)ft_strlen(s);
	if (!(tmp = (char *)malloc(len + 1)))
		return (NULL);
	while (i < len)
	{
		tmp[i] = f(i, s[i]);
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
