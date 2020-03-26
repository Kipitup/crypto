/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_build.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 11:15:55 by amartino          #+#    #+#             */
/*   Updated: 2020/03/12 14:20:17 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

static void		insert_node(t_heap *heap, int32_t nb, size_t index)
{
	heap->array[index] = nb;
	heap->array[HEAP_SIZE]++;
	is_parent_valid(heap, index);
}

void			delete_root(t_heap *heap)
{
	size_t	size;

	size = heap->array[HEAP_SIZE];
	heap->array[ROOT] = heap->array[size];
	heap->array[size] = 0;
	heap->array[HEAP_SIZE]--;
	heapify(heap, ROOT);
}

static void		fill_tree(t_heap *heap, int32_t *tab, size_t size)
{
	size_t		i;
	size_t		parent_index;

	i = 1;
	parent_index = 1;
	heap->array[1] = tab[0];
	heap->array[HEAP_SIZE]++;;
	while (i < size)
	{
		insert_node(heap, tab[i], get_left_child(parent_index));
		i++;
		if (i < size)
			insert_node(heap, tab[i], get_right_child(parent_index));
		i++;
		parent_index++;
	}
}

t_heap			*heap_tree(int32_t *tab, size_t size, uint8_t type)
{
	t_heap		*heap;

	heap = ft_memalloc(sizeof(t_heap));
	if (heap != NULL)
		heap->array = ft_memalloc(sizeof(int32_t) * (size + 1));
	if (heap == NULL || heap->array == NULL)
		ft_memdel((void**)&heap);
	else
	{
		heap->type = type;
		heap->array[HEAP_SIZE] = 0;
		fill_tree(heap, tab, size);
	}
	return (heap);
}
