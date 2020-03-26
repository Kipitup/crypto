/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_addstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 17:17:56 by amartino          #+#    #+#             */
/*   Updated: 2020/01/20 11:40:38 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/*
**	Add a str to the end of the vector string.
**
**	As for all vectors functions, if the LENGHT of the new string is bigger
**	than the string SIZE, an equivalent reallocation occurs.
*/

int8_t	vct_addstr(t_vector *vector, char *str)
{
	size_t	len;
	int8_t	ret;

	ret = FAILURE;
	if (vector != NULL && vector->str != NULL && str != NULL)
	{
		ret = SUCCESS;
		len = ft_strlen(str);
		if (len + vector->len >= vector->size)
			ret = vct_increase_scale(vector, len + DEFAULT_VCT_SCALE);
		if (ret == SUCCESS)
		{
			ft_memcpy(vector->str + vector->len, str, len);
			vector->len += len;
		}
	}
	return (ret);
}
