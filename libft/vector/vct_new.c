/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 16:35:59 by amartino          #+#    #+#             */
/*   Updated: 2020/02/28 11:19:22 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/*
**	Return a new vector.
**
**	The size parameter is the lenght of the string with the '\0'.
*/

t_vector		*vct_new(size_t size)
{
	t_vector	*new_vector;

	new_vector = (t_vector *)ft_memalloc(sizeof(t_vector));
	if (new_vector != NULL)
	{
		new_vector->size = size == 0 ? DEFAULT_VCT_SIZE : size;
		new_vector->len = 0;
		new_vector->scale = DEFAULT_VCT_SCALE;
		new_vector->str = ft_memalloc(new_vector->size);
		if (new_vector->str == NULL)
			vct_del(&new_vector);
	}
	return (new_vector);
}
