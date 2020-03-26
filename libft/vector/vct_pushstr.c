/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_pushstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 11:32:56 by amartino          #+#    #+#             */
/*   Updated: 2020/02/26 16:23:19 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/*
**	Add a string at the beginning of the vector string
**
**	As for all vectors functions, if the LENGHT of the new string is bigger
**	than the string SIZE, an equivalent reallocation occurs.
*/

int8_t			vct_pushstr(t_vector *vector, char *str)
{
	size_t	len;
	int8_t	ret;

	ret = FAILURE;
	if (vector != NULL && vector->str != NULL && str != NULL)
	{
		ret = SUCCESS;
		len = ft_strlen(str);
		if (vector->len + len >= vector->size)
			ret = vct_increase_scale(vector, len);
		if (ret == SUCCESS)
		{
			ft_memmove(vector->str + len, vector->str, vector->len);
			ft_memcpy(vector->str, str, len);
			vector->len += len;
			vector->str[vector->len] = '\0';
		}
	}
	return (ret);
}
