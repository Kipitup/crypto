/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 14:54:09 by amartino          #+#    #+#             */
/*   Updated: 2019/09/03 17:14:29 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/*
** Return the len of the vector
*/

size_t	vct_len(t_vector *vector)
{
	if (vector == NULL)
		return (0);
	return (vector->len);
}
