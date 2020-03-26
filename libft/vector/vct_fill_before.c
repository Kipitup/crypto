/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_fill_before.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 09:29:07 by fkante            #+#    #+#             */
/*   Updated: 2019/09/20 10:15:48 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/*
**	Fill the vector from the beginning of the string with a given number (size)
**	of char (c)
**
**	As for all vectors functions, if the LENGHT of the new string is bigger
**	than the string SIZE, an equivalent reallocation occurs.
*/

int8_t	vct_fill_before(t_vector *vector, char c, size_t size)
{
	size_t	start;
	int8_t	ret;

	ret = FAILURE;
	start = 0;
	if (vector != NULL && vector->str != NULL)
	{
		ret = SUCCESS;
		if (vector->len + size >= vector->size)
			ret = vct_increase_scale(vector, size);
		if (ret == SUCCESS)
		{
			while (size > 0)
			{
				ret = vct_addchar_at(vector, c, start);
				if (ret == FAILURE)
					break ;
				size--;
			}
		}
	}
	return (ret);
}
