/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:35:14 by fkante            #+#    #+#             */
/*   Updated: 2020/03/10 19:25:53 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"
#include "darray.h"
#include "libft.h"

static int8_t		should_map_resize(t_hashmap *map)
{
	size_t		limit;
	int8_t		ret;

	ret = SUCCESS;
	limit = (size_t)ft_log2_n(map->size);
	if (map->nb_collision >= limit)
		ret = hashmap_resize(map);
	return (ret);
}

static int8_t		push_node(t_hashmap *map, t_hashnode *node, uint32_t hash)
{
	t_darray	*array;
	size_t		index;
	int8_t		ret;

	ret = FAILURE;
	index = hash % map->size;
	if (map->bucket[index] == NULL)
	{
		array = darray_create(sizeof(t_hashnode*), DEFAULT_ARRAY_SIZE);
		if (array != NULL)
		{
			ret = darray_set(array, 0, (void*)node);
			if (ret == SUCCESS)
				map->bucket[index] = array;
			else
				darray_clear_destroy(&array, &del_hashmap_node);
		}
	}
	else
	{
		ret = darray_push(map->bucket[index], (void*)node);
		map->nb_collision++;
	}
	return (ret);
}

int8_t				hashmap_set(t_hashmap *map, void *key, void *data)
{
	t_hashnode	*node;
	uint32_t	hash;
	int8_t		ret;

	if (map != NULL && key != NULL && data != NULL)
	{
		hash = map->hash(key, ft_strlen((char*)key));
		node = hash_node_create(key, data, hash);
		if (node != NULL)
		{
			ret = push_node(map, node, hash);
			map->nb_of_elem++;
			ret = should_map_resize(map);
		}
		else
			ret = ft_perror_failure(NODE_NULL, __FILE__, __LINE__);
	}
	else
		ret = ft_perror_failure(INPUT_NULL, __FILE__, __LINE__);
	return (ret);
}
