/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 12:03:27 by fkante            #+#    #+#             */
/*   Updated: 2020/03/12 12:22:53 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(uint32_t, char *))
{
	uint32_t	i;
	uint32_t	l;

	if (s == NULL || f == NULL)
		return ;
	i = 0;
	l = (uint32_t)ft_strlen(s);
	while (i < l)
	{
		f(i, &s[i]);
		i++;
	}
}
