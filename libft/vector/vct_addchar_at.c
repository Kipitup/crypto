/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_addchar_at.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 10:43:28 by amartino          #+#    #+#             */
/*   Updated: 2019/09/20 10:32:05 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/*
**	Add a char at a given index of the vector string
**
**	As for all vectors functions, if the LENGHT of the new string is bigger
**	than the string SIZE, an equivalent reallocation occurs.
*/

int8_t	vct_addchar_at(t_vector *vector, char c, size_t index)
{
	int8_t	ret;

	ret = FAILURE;
	if (vector != NULL && vector->str != NULL)
	{
		ret = SUCCESS;
		if (vector->len + 1 >= vector->size)
			ret = vct_increase_scale(vector, 0);
		if (ret == SUCCESS)
		{
			if (index > vector->len)
				vct_addchar(vector, c);
			else
			{
				ft_memmove(vector->str + index + 1, vector->str + index,
						vector->len - index);
				vector->str[index] = c;
				vector->len++;
				vector->str[vector->len] = '\0';
			}
		}
	}
	return (ret);
}
