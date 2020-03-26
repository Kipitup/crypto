/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   darray_modify_size.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 14:59:46 by fkante            #+#    #+#             */
/*   Updated: 2020/03/05 11:23:51 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "darray.h"
#include "libft.h"

static int8_t	darray_resize(t_darray *array, size_t newsize)
{
	void	**new_content;
	size_t	old_max;
	int8_t	ret;

	ret = FAILURE;
	if (array == NULL)
		ret = ft_perror_failure(ARRAY_IS_NULL, __FILE__, __LINE__);
	else if (newsize == 0)
		ret = ft_perror_failure(NEWSIZE_ZERO, __FILE__, __LINE__);
	else
	{
		old_max = array->max;
		array->max = newsize;
		new_content = ft_realloc(array, array->max, old_max);
		if (new_content != NULL)
		{
			array->contents = new_content;
			ret = SUCCESS;
		}
		else
			ft_perror_failure(FAILED_TO_EXPAND, __FILE__, __LINE__);
	}
	return (ret);
}

/*
** Since array->max is an index
*/

int8_t			darray_expand(t_darray *array)
{
	size_t	old_max;
	int8_t	ret;

	ret = FAILURE;
	if (array != NULL)
	{
		old_max = array->max;
		ret = darray_resize(array, array->max + array->expand_rate);
		if (ret == SUCCESS)
			ft_memset(array->contents + old_max, 0, array->expand_rate);
	}
	else
		ft_perror(ARRAY_IS_NULL, __FILE__, __LINE__);
	return (ret);
}

int8_t			darray_contract(t_darray *array)
{
	size_t newsize;

	if (array != NULL)
	{
		newsize = (array->end < array->expand_rate) ? array->expand_rate
			: array->end;
		return (darray_resize(array, newsize));
	}
	else
		return (ft_perror_failure(ARRAY_IS_NULL, __FILE__, __LINE__));
}
