/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_chr_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 18:51:15 by amartino          #+#    #+#             */
/*   Updated: 2020/01/31 18:57:22 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/*
**	Search a character in the string and return number of match found.
*/

size_t	vct_chr_count(t_vector *vector, char c)
{
	size_t	index;
	size_t	count;

	index = 0;
	count = 0;
	while (index <= vector->len)
	{
		if (vector->str[index] == c)
			count++;
		index++;
	}
	return (count);
}
