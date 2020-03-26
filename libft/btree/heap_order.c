/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_order.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 11:03:55 by amartino          #+#    #+#             */
/*   Updated: 2020/03/12 14:22:32 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

void	swap(t_heap *heap, size_t parent, size_t child)
{
	int32_t		tmp;

	tmp = heap->array[parent];
	heap->array[parent] = heap->array[child];
	heap->array[child] = tmp;
}

void 	is_parent_valid(t_heap *heap, size_t child)
{
	size_t		p;

	p = get_heap_parent(child);
	if ((heap->type == MIN_HEAP && heap->array[p] > heap->array[child]) == TRUE
	 || (heap->type == MAX_HEAP && heap->array[p] < heap->array[child]) == TRUE)
	{
		swap(heap, p, child);
		is_parent_valid(heap, p);
	}
}

void	heapify(t_heap *heap, size_t parent)
{
	size_t		l;
	size_t		r;
	size_t		extremum;

	l = get_left_child(parent);
	l = (int32_t)l > heap->array[HEAP_SIZE] ? parent : l;
	r = get_right_child(parent);
	r = (int32_t)r > heap->array[HEAP_SIZE] ? parent : r;
	if (heap->type == MIN_HEAP)
	{
		extremum = heap->array[parent] > heap->array[l] ? l : parent;
		extremum = heap->array[extremum] > heap->array[r] ? r : extremum;
	}
	else
	{
		extremum = heap->array[parent] < heap->array[l] ? l : parent;
		extremum = heap->array[extremum] < heap->array[r] ? r : extremum;
	}
	if (extremum != parent)
	{
		swap(heap, parent, extremum);
		heapify(heap, extremum);
	}
}
