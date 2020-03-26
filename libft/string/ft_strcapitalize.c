/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:32:58 by amartino          #+#    #+#             */
/*   Updated: 2020/03/12 13:47:43 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcapitalize(char *str)
{
	int		i;

	i = 1;
	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] -= 32;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		if ((str[i] >= 'a' && str[i] <= 'z'))
		{
			if (!(str[i - 1] >= 'a' && str[i - 1] <= 'z')
					&& !(str[i - 1] >= 'A' && str[i - 1] <= 'Z')
					&& !(str[i - 1] >= '0' && str[i - 1] <= '9'))
				str[i] -= 32;
		}
		i++;
	}
	return (str);
}
