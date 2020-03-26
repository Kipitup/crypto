/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_median.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 12:01:11 by amartino          #+#    #+#             */
/*   Updated: 2020/03/12 14:35:08 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

int8_t		ft_median(int32_t *tab, size_t size, int32_t *median)
{
	t_heap		*heap;
	size_t		over_half;

	over_half = (size / 2) + 1;
	heap = heap_tree(tab, over_half, MIN_HEAP);
	if (heap == NULL)
		return (FAILURE);
	while (over_half < size)
	{
		if (tab[over_half] > heap->array[ROOT])
		{
			heap->array[ROOT] = tab[over_half];
			heapify(heap, ROOT);
		}
		over_half++;
	}
	*median = heap->array[ROOT];
	clean_heap_tree(&heap);
	return (SUCCESS);
} 
