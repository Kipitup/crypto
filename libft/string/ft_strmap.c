/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:34:31 by fkante            #+#    #+#             */
/*   Updated: 2020/03/12 12:25:40 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t		i;
	size_t		len;
	char		*tmp;

	if (s == NULL || f == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	tmp = (char *)ft_memalloc(len + 1);
	if (tmp != NULL)
	{
		while (i < len)
		{
			tmp[i] = f(s[i]);
			i++;
		}
		tmp[i] = '\0';
	}
	return (tmp);
}
