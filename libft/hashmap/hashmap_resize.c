/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_resize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <a.martino@sutdent.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 18:31:14 by amartino          #+#    #+#             */
/*   Updated: 2020/03/09 15:53:37 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "hashmap.h"
#include "darray.h"

static int8_t	push_node(void **bucket, size_t map_size, size_t *nb_collision,
		t_hashnode *node)
{
	t_darray	*array;
	size_t		index;
	int8_t		ret;

	ret = FAILURE;
	index = node->hash % map_size;
	if (bucket[index] == NULL)
	{
		array = darray_create(sizeof(t_hashnode*), DEFAULT_ARRAY_SIZE);
		if (array != NULL)
		{
			ret = darray_set(array, 0, (void*)node);
			if (ret == SUCCESS)
				bucket[index] = array;
			else
				darray_clear_destroy(&array, &del_hashmap_node);
		}
	}
	else
	{
		ret = darray_push(bucket[index], (void*)node);
		nb_collision++;
	}
	return (ret);
}

static int8_t	handle_collision(t_darray *array, void **content, size_t n_size,
									size_t *nb_collision)
{
	t_hashnode	*node;
	size_t		i;
	int8_t		ret;

	i = 1;
	ret = FAILURE;
	while (i <= array->end)
	{
		node = darray_get(array, i);
		if (node != NULL)
		{
			ret = push_node(content, n_size, nb_collision, node);
			darray_remove(array, i);
		}
		else
			ft_perror(NODE_SEARCH_NULL, __FILE__, __LINE__);
		i++;
	}
	return (ret);
}

static int8_t	redispatch_node(t_hashmap *map, size_t i, void **content,
									size_t new_size)
{
	t_hashnode	*node;
	t_darray	*array;
	size_t		index;
	int8_t		ret;

	ret = FAILURE;
	array = map->bucket[i];
	if (array != NULL)
	{
		node = darray_get(array, 0);
		if (node != NULL)
		{
			index = node->hash % new_size;
			content[index] = array;
			if (array->end > 0)
			{
				ret = handle_collision(array, content, new_size,
										&map->nb_collision);
			}
		}
	}
	return (ret);
}

int8_t			hashmap_resize(t_hashmap *map)
{
	void		**content;
	size_t		new_size;
	size_t		i;
	int8_t		ret;

	i = 0;
	ret = SUCCESS;
	new_size = (size_t)ft_find_next_prime(map->size * 3);
	content = ft_memalloc(new_size * (sizeof(t_darray*)));
	if (content != NULL)
	{
		map->nb_collision = 0;
		while (i < map->size)
		{
			redispatch_node(map, i, content, new_size);
			i++;
		}
		free(map->bucket);
		map->bucket = content;
		map->size = new_size;
	}
	else
		ret = ft_perror_failure(RESIZE_FAIL, __FILE__, __LINE__);
	return (ret);
}
