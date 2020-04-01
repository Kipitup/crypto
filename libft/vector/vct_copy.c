/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartinod <a.martino@sutdent.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:45:11 by amartinod         #+#    #+#             */
/*   Updated: 2020/04/01 18:32:19 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/*
**	Add a char at a given index of the string
**
**	As for all vectors functions, if the LENGHT of the new string is bigger
**	than the string SIZE, an equivalent reallocation occurs.
*/
void		vct_copy(t_vector *dest, t_vector *src)
{
	size_t	i;

	i = 0;
	if (src != NULL && dest != NULL)
	{
		while (i < src->len && i < dest->len)
		{
			dest->str[i] = src->str[i];
			i++;
		}
	}
}
