/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_addnb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 11:35:21 by amartino          #+#    #+#             */
/*   Updated: 2020/01/20 11:48:05 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/*
**	Convert tuhe number into a string and add it to the end of the string
**
**	As for all vectors functions, if the LENGHT of the new string is bigger
**	than the string SIZE, an equivalent reallocation occurs.
*/

int8_t			vct_addnb(t_vector *vector, int64_t nb)
{
	char		*str;
	int8_t		ret;

	ret = FAILURE;
	if (vector != NULL && vector->str != NULL)
	{
		ret = SUCCESS;
		if ((str = ft_itoa(nb)) != NULL)
			if ((vct_addstr(vector, str)) == FAILURE)
				vct_del(&vector);
		ft_strdel(&str);
		if (vector == NULL)
			ret = FAILURE;
	}
	return (ret);
}
