/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_clean.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 16:42:38 by fkante            #+#    #+#             */
/*   Updated: 2020/03/09 16:18:53 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"
#include "libft.h"
#include "darray.h"

void	del_map(t_hashmap **map_to_del)
{
	t_hashmap	*map;
	size_t		i;

	i = 0;
	if (map_to_del != NULL && *map_to_del != NULL)
	{
		map = *map_to_del;
		while (i < map->size)
		{
			if (map->bucket[i] != NULL)
				darray_clear_destroy((t_darray**)&(map->bucket[i]),
										&del_hashmap_node);
			i++;
		}
		ft_memdel((void**)&(map->bucket));
		ft_memdel((void**)map_to_del);
	}
}
