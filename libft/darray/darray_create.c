/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   darray_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:04:30 by fkante            #+#    #+#             */
/*   Updated: 2020/03/05 17:34:19 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "darray.h"
#include "libft.h"

t_darray	*darray_create(size_t sizeof_elem, size_t init_max)
{
	t_darray	*array;

	array = NULL;
	if (init_max > 0)
	{
		array = ft_memalloc(sizeof(t_darray));
		if (array != NULL)
		{
			array->end = 0;
			array->max = init_max;
			array->sizeof_elem = sizeof_elem;
			array->expand_rate = DEFAULT_EXPAND_RATE;
			array->contents = ft_memalloc(init_max * sizeof(void *));
			if (array->contents == NULL)
			{
				darray_destroy(&array);
				ft_perror_null(CONTENT_FAIL, __FILE__, __LINE__);
			}
		}
	}
	else
		ft_perror_null(INITIAL_MAX_ZERO, __FILE__, __LINE__);
	return (array);
}
