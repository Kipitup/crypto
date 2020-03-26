/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_sub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 15:57:53 by amartino          #+#    #+#             */
/*   Updated: 2020/02/10 20:38:02 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector 	*vct_sub(t_vector *vector, size_t start, size_t len)
{
	t_vector	*new_vector;

	if (vector == NULL || vector->str == NULL || start > vector->len)
		return (NULL);
	len = len > (vector->len - start) ? (vector->len - start) : len;
	new_vector = vct_new(len + 1);
	if (new_vector != NULL)
	{
		ft_strncpy(new_vector->str, (vector->str + start), len);
		new_vector->len = len;
	}
	return (new_vector);
}
