/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_fill_after.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 09:11:00 by fkante            #+#    #+#             */
/*   Updated: 2019/09/12 17:15:09 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/*
**	Fill the vector from the end of the string with a given number (size)
**	of char (c)
**
**	As for all vectors functions, if the LENGHT of the new string is bigger
**	than the string SIZE, an equivalent reallocation occurs.
*/

int8_t		vct_fill_after(t_vector *vector, char c, size_t size)
{
	if (vector != NULL && vector->str != NULL)
	{
		if (vector->len + size >= vector->size)
			if (vct_increase_scale(vector, size) == FAILURE)
				vct_del(&vector);
		if (vector != NULL)
		{
			while (size > 0)
			{
				vector->str[vector->len++] = c;
				size--;
			}
			vector->str[vector->len] = '\0';
		}
	}
	return (vector == NULL ? FAILURE : SUCCESS);
}
