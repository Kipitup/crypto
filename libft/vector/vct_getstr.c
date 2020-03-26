/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_getstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 15:06:11 by amartino          #+#    #+#             */
/*   Updated: 2019/09/20 10:17:25 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/*
**	Return a pointer on the vector string
*/

char	*vct_getstr(t_vector *vector)
{
	char	*str;

	str = NULL;
	if (vector != NULL && vector->str != NULL)
		str = vector->str;
	return (str);
}
