/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_addnstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 13:31:03 by amartino          #+#    #+#             */
/*   Updated: 2020/02/06 13:32:22 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/*
**	Add a nb of characters (len) of a string (str) to the end of the vector str.
**
**	As for all vectors functions, if the LENGHT of the new string is bigger
**	than the string SIZE, an equivalent reallocation occurs.
*/

int8_t	vct_addnstr(t_vector *vector, char *str, size_t len)
{
	int8_t	ret;

	ret = FAILURE;
	if (vector != NULL && vector->str != NULL && str != NULL)
	{
		ret = SUCCESS;
		if (len + vector->len >= vector->size)
			ret = vct_increase_scale(vector, len + DEFAULT_VCT_SCALE);
		if (ret == SUCCESS)
		{
			ft_memcpy(vector->str + vector->len, str, len);
			vector->len += len;
		}
	}
	return (ret);
}
