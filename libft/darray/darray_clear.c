/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   darray_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 10:35:38 by fkante            #+#    #+#             */
/*   Updated: 2020/03/10 18:47:12 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "darray.h"
#include "libft.h"

void	darray_clear_content(t_darray **array_to_del, t_del_func del_func)
{
	size_t 		i;
	t_darray	*array;

	i = 0;
	if (array_to_del != NULL && *array_to_del != NULL)
	{
		array = *array_to_del;
		if (array->sizeof_elem > 0)
		{
			while (i <= array->end)
			{
				if (array->contents[i] != NULL)
				{
					del_func(array->contents[i]);
					array->contents[i] = NULL;
				}
				i++;
			}
		}
	}
	else
		ft_perror(CLEAR_NULL, __FILE__, __LINE__);
}
