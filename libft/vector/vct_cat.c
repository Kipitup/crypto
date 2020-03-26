/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_cat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 14:57:15 by amartino          #+#    #+#             */
/*   Updated: 2019/09/18 19:33:49 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/*
**	Concat 2 vector string.
**
**	As for all vectors functions, if the LENGHT of the new string is bigger
**	than the string SIZE, an equivalent reallocation occurs.
*/

int8_t	vct_cat(t_vector *dest, t_vector *src)
{
	int8_t		ret;

	ret = FAILURE;
	if (dest != NULL && dest->str != NULL
		&& src != NULL && src->str != NULL)
	{
		ret = SUCCESS;
		if (src->len + dest->len + 1 >= dest->size)
			ret = vct_increase_scale(dest, src->size);
		if (ret == SUCCESS)
		{
			ft_memmove(dest->str + dest->len, src->str, src->len);
			dest->len += src->len;
			dest->str[dest->len] = '\0';
		}
	}
	return (ret);
}
