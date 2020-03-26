/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_getchar_at.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:11:18 by amartino          #+#    #+#             */
/*   Updated: 2019/09/20 11:22:37 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

char	vct_getchar_at(t_vector *vector, size_t index)
{
	char c;

	c = 0;
	if (vector != NULL && vector->str != NULL)
	{
		if (index >= vct_len(vector))
			index = vct_len(vector) > 0 ? vct_len(vector) - 1 : 0;
		c = vector->str[index];
	}
	return (c);
}
