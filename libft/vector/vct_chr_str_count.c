/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_chr_str_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 19:02:41 by amartino          #+#    #+#             */
/*   Updated: 2020/02/03 15:01:42 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

size_t		vct_chr_str_count(t_vector *vector, char *find)
{
	size_t		index;
	size_t		count;
	size_t		j;

	index = 0;
	count = 0;
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
				count++;
		}
		else
			index++;
	}
	return (count);
}
