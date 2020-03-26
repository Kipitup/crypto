/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_pop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 17:04:17 by amartino          #+#    #+#             */
/*   Updated: 2019/09/04 17:44:44 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/*
**	Remove a certain number of characters from the end of the string
*/

void			vct_pop(t_vector *vector, size_t len)
{
	size_t start;

	if (vector != NULL && vector->str != NULL)
	{
		start = vector->len - len;
		ft_bzero((vector->str + start), len);
		vector->len -= len;
	}
}
