/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 11:25:17 by fkante            #+#    #+#             */
/*   Updated: 2020/03/09 10:24:42 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "darray.h"

void		**ft_realloc(t_darray *array, size_t new_size, size_t old_size)
{
	void	**tmp;
	size_t	i;

	i = 0;
	tmp = NULL;
	new_size = (new_size > old_size) ? new_size : old_size;
	if (array != NULL && new_size > 0)
	{
		tmp = ft_memalloc(new_size * sizeof(void*));
		if (tmp != NULL)
		{
			while (i <= array->end)
			{
				tmp[i] = array->contents[i];
				i++;
			}
			ft_memdel((void**)&array->contents);
		}
		else
			ft_perror_null(REALLOC_FAIL, __FILE__, __LINE__);
	}
	return (tmp);
}
