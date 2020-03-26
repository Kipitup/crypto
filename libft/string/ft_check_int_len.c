/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_int_len.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:16:42 by amartino          #+#    #+#             */
/*   Updated: 2020/02/26 18:24:14 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int8_t		ft_check_int_len(char *str)
{
	size_t	i;
	size_t	len;
	int8_t	ret;

	i = 0;
	ret = SUCCESS;
	len = ft_strlen(str);
	if (len > INTMIN_LEN)
	{
		if (str[i] == '-')
			i++;
		while (str[i] != '\0' && str[i] == '0')
			i++;
		len = ft_strlen(str + i);
		if (len > INTMAX_LEN)
			ret = FAILURE;
	}
	return (ret);
}
