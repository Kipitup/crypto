/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_addstr_at.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 13:09:14 by amartino          #+#    #+#             */
/*   Updated: 2019/09/20 10:31:29 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/*
**	Add a string at a given index of the vector string
**
**	As for all vectors functions, if the LENGHT of the new string is bigger
**	than the string SIZE, an equivalent reallocation occurs.
*/

int8_t			vct_addstr_at(t_vector *vector, char *str, size_t index)
{
	size_t	len;
	int8_t	ret;

	ret = FAILURE;
	if (vector != NULL && vector->str != NULL)
	{
		ret = SUCCESS;
		len = ft_strlen(str);
		if (vector->len + len >= vector->size)
			ret = vct_increase_scale(vector, len);
		if (ret == SUCCESS)
		{
			ft_memmove(vector->str + index + len, vector->str + index,
				vector->len - index);
			ft_memcpy(vector->str + index, str, len);
			vector->len += len;
			vector->str[vector->len] = '\0';
		}
	}
	return (ret);
}
