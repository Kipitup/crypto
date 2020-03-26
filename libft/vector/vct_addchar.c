/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_addchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 17:34:15 by amartino          #+#    #+#             */
/*   Updated: 2019/09/20 10:13:56 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/*
**	Add a char to the end of the string
**
**	As for all vectors functions, if the LENGHT of the new string is bigger
**	than the string SIZE, an equivalent reallocation occurs.
*/

int8_t			vct_addchar(t_vector *vector, char c)
{
	int8_t		ret;

	ret = FAILURE;
	if (vector != NULL && vector->str != NULL)
	{
		ret = SUCCESS;
		if (vector->len + 1 >= vector->size)
			ret = vct_increase_scale(vector, 0);
		if (ret == SUCCESS)
		{
			vector->str[vector->len] = c;
			vector->str[vector->len + 1] = '\0';
			vector->len += 1;
		}
	}
	return (ret);
}
