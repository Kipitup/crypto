/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_chr_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 13:23:12 by amartino          #+#    #+#             */
/*   Updated: 2020/03/28 16:32:56 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/*
**	Search the vector for a given string. If found, return the index of the
**	start of the string. If not, return FAILURE.
*/

ssize_t		vct_chr_str(t_vector *vector, char *find)
{
	size_t		index;
	size_t		j;

	index = 0;
	while (index <= vector->len)
	{
		j = 0;
		if (vector->str[index] == find[j])
		{
			while (find[j] != '\0')
			{
				if (vector->str[index] != find[j])
					break ;
				index++;
				j++;
			}
			if (find[j] == '\0')
				return (index - j);
		}
		else
			index++;
	}
	return (FAILURE);
}
