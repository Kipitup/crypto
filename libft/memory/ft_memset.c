/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 19:11:30 by fkante            #+#    #+#             */
/*   Updated: 2020/03/03 13:58:27 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buff, int c, size_t len)
{
	size_t		i;

	i = 0;
	if (len == 0)
		return (buff);
	while (i < len)
	{
		((unsigned char*)buff)[i] = (unsigned char)c;
		i++;
	}
	return (buff);
}
