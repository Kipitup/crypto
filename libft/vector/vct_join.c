/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_join.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 14:05:07 by amartino          #+#    #+#             */
/*   Updated: 2019/09/05 14:56:46 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/*
**	Join 2 vector string together. Return the new joined vector. If one of the
**	the string is NULL, the other one is duplicate and return.
**
**	The size of the new vector will be the len of dest + src + dest->scale.
**
**	As for all vectors functions, if the LENGHT of the new string is bigger
**	than the string SIZE, an equivalent reallocation occurs.
*/

t_vector	*vct_join(t_vector *dest, t_vector *src)
{
	t_vector	*new;

	if (dest == NULL && src == NULL)
		new = NULL;
	else if (dest == NULL)
		new = vct_dup(src);
	else if (src == NULL)
		new = vct_dup(dest);
	else
	{
		new = vct_new(dest->len + src->len + DEFAULT_VCT_SCALE);
		if (new != NULL)
		{
			ft_memmove(new->str, dest->str, dest->len);
			ft_memmove(new->str + dest->len, src->str, src->len);
			new->len = dest->len + src->len;
			new->str[new->len] = '\0';
		}
	}
	return (new);
}
