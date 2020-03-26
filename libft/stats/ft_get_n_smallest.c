/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_n_smallest.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 21:08:05 by amartino          #+#    #+#             */
/*   Updated: 2020/03/12 14:35:41 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"
#include <stdio.h>

ssize_t		ft_get_n_smallest(int32_t *tab, size_t nth, size_t start,
								size_t limit)
{
	t_heap	*heap;
	size_t	i;

	i = start;
	heap = heap_tree((tab + start), limit, MIN_HEAP);
	if (heap == NULL || nth == 0)
		return (FAILURE);
	while (nth > 1)
	{
		delete_root(heap);
		nth--;
	}
	while (i < (limit + start))
	{
		if (tab[i] == heap->array[ROOT])
			break ;
		i++;
	}
	clean_heap_tree(&heap);
	return (i);
}
