/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_replace_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 11:34:06 by amartino          #+#    #+#             */
/*   Updated: 2020/02/03 15:10:53 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/*
**	Replace all given char of a string to the given replace char.
*/

ssize_t			vct_replace_char(t_vector *vector, char c, char replace)
{
	size_t		index;
	ssize_t		ret;

	index = 0;
	ret = 0;
	if (vector != NULL && vector->str != NULL)
	{
		while (index < vector->len)
		{
			if (vector->str[index] == c)
			{
				vector->str[index] = replace;
				ret++;
			}
			index++;
		}
	}
	return (vector == NULL ? FAILURE : ret);
}
