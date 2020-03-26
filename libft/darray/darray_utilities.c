/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   darray_utilities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 13:36:23 by fkante            #+#    #+#             */
/*   Updated: 2020/03/04 17:02:31 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "darray.h"
#include "libft.h"

int8_t	darray_set(t_darray *array, size_t i, void *element)
{
	int8_t	ret;

	ret = FAILURE;
	if (array != NULL)
	{
		if (i < array->max)
		{
			if (i > array->end)
				array->end = i;
			array->contents[i] = element;
			ret = SUCCESS;
		}
		else
			ft_perror_failure(SET_ABOVE_MAX, __FILE__, __LINE__);
	}
	else
		ft_perror_failure(ARRAY_IS_NULL, __FILE__, __LINE__);
	return (ret);
}

void	*darray_get(t_darray *array, size_t i)
{
	if (array != NULL)
	{
		if (i < array->max)
			return (array->contents[i]);
		else
			return (ft_perror_null(GET_ABOVE_MAX, __FILE__, __LINE__));
	}
	else
		return (ft_perror_null(ARRAY_IS_NULL, __FILE__, __LINE__));

}

void	*darray_remove(t_darray *array, size_t index)
{
	void	*element;

	element = NULL;
	if (array != NULL)
	{
		element = array->contents[index];
		array->contents[index] = NULL;
	}
	else
		ft_perror(ARRAY_IS_NULL, __FILE__, __LINE__);
	return (element);
}

void	*darray_new(t_darray *array)
{
	if (array != NULL)
	{
		if (array->sizeof_elem > 0)
			return (ft_memalloc(array->sizeof_elem));
		else
			return (ft_perror_null(ARRAY_SIZE_ZERO, __FILE__, __LINE__));
	}
	return (ft_perror_null(ARRAY_IS_NULL, __FILE__, __LINE__));
}
