/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_joinfree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 15:14:53 by amartino          #+#    #+#             */
/*   Updated: 2020/02/26 10:53:00 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/*
**	Join 2 vector string together. Return the new joined vector. If one of the
**	the string is NULL, the other one is duplicate and return.
**
**	The size of the new vector will be the len of dest + src + dest->scale.
**
**	FIRST, only the dest will be freed. SECOND, src and BOTH dest + src will be
**	freed.
**
**	As for all vectors functions, if the LENGHT of the new string is bigger
**	than the string SIZE, an equivalent reallocation occurs.
*/

t_vector	*vct_joinfree(t_vector **dest, t_vector **src,
							int first_or_second_or_both)
{
	t_vector	*new;

	new = vct_join(*dest, *src);
	if (first_or_second_or_both == FIRST)
		vct_del(dest);
	else if (first_or_second_or_both == SECOND)
		vct_del(src);
	else
	{
		vct_del(dest);
		vct_del(src);
	}
	return (new);
}
