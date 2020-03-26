/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_ndup_from.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 10:56:01 by amartino          #+#    #+#             */
/*   Updated: 2020/02/27 13:56:41 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/*
**	Return a duplicate portion of the given vector from index
*/

t_vector	*vct_ndup_from(t_vector *vector, size_t len, size_t index)
{
	t_vector	*dup;

	dup = NULL;
	if (vector != NULL && vector->str != NULL)
	{
		if (len > vector->len)
			len = vector->len;
		dup = vct_new(len);
		if (dup != NULL && index <= vector->len)
		{
			if (vct_addnstr(dup, (vector->str + index), len) == FAILURE)
				vct_del(&dup);
		}
	}
	return (dup);
}
