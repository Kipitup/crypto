/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_chr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 11:55:59 by amartino          #+#    #+#             */
/*   Updated: 2020/03/12 14:33:36 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/*
**	Search a character in the string and return the index of the first match
**	it find.
*/
ssize_t	vct_chr(t_vector *vector, char c)
{
	ssize_t	index;

	index = 0;
	while (index <= vector->len)
	{
		if (vector->str[index] == c)
			return (index);
		index++;
	}
	return (FAILURE);
}
