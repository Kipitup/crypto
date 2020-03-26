/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 18:00:01 by fkante            #+#    #+#             */
/*   Updated: 2020/03/10 19:22:46 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"
#include "darray.h"
#include "libft.h"

void		print_node(t_hashnode *node)
{
	if (node != NULL)
	{
		ft_printf("\n\t- key: {c_green}%s{c_end}\n\t- data: %s\n\t- hash: %u\n",
				(char*)node->key, (char*)node->data, node->hash);
	}
}

static void	print_hashmap_bis(t_darray *array)
{
	t_hashnode	*node;
	size_t		index_node;

	index_node = 0;
	while (index_node <= array->end)
	{
		node = darray_get(array, index_node);
		if (node != NULL)
		{
			ft_printf("-> node %d:", index_node);
			print_node(node);
		}
		index_node++;
	}
}

void		print_hashmap(t_hashmap *map)
{
	t_darray	*array;
	size_t		index_bucket;

	index_bucket = 0;
	if (map != NULL)
	{
		ft_printf("Number of collision = %d\n", map->nb_collision);
		while (index_bucket < map->size)
		{
			array = map->bucket[index_bucket];
			if (array != NULL)
			{
				ft_printf("{c_cyan}---------------------------------{c_end}\n");
				ft_printf("Index = %d\n", index_bucket);
				print_hashmap_bis(array);
			}
			index_bucket++;
		}
	}
}
