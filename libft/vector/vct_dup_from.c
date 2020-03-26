/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_dup_from.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 10:56:01 by amartino          #+#    #+#             */
/*   Updated: 2020/02/27 13:40:54 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/*
**	Return a duplicate of the given vector from index n
*/

t_vector	*vct_dup_from(t_vector *vector, size_t index)
{
	t_vector	*dup;

	dup = NULL;
	if (vector != NULL && vector->str != NULL)
	{
		if (index > vector->len)
			dup = vct_new(0);
		else
		{
			dup = vct_new(vector->size - index);
			if (dup != NULL)
			{
				if (vct_pushstr(dup, (vector->str + index)) == FAILURE)
					vct_del(&dup);
			}

		}
	}
	return (dup);
}
