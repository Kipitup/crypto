/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_ndup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 10:56:01 by amartino          #+#    #+#             */
/*   Updated: 2020/02/27 13:49:00 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/*
**	Return a duplicate portion (len) of the given vector.
*/

t_vector	*vct_ndup(t_vector *vector, size_t len)
{
	t_vector	*dup;

	dup = NULL;
	if (vector != NULL && vector->str != NULL)
	{
		if (len > vector->len)
			len = vector->len;
		dup = vct_new(len);
		if (dup != NULL)
		{
			if (vct_addnstr(dup, vector->str, len) == FAILURE)
				vct_del(&dup);
		}
	}
	return (dup);
}
