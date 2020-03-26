/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 12:38:52 by amartino          #+#    #+#             */
/*   Updated: 2020/03/12 14:36:28 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

int32_t				*ft_sort(int32_t *tab, size_t size)
{
	t_heap	*heap;
	int32_t	*sorted_array;
	size_t	i;

	i = 0;
	heap = heap_tree(tab, size, MIN_HEAP);
	sorted_array = ft_memalloc(sizeof(int32_t) * size);
	if (sorted_array == NULL && heap == NULL)
		return (ft_perror_null("memory allocation failed", __FILE__, __LINE__));
	while (i < size)
	{
		sorted_array[i] = heap->array[ROOT];
		delete_root(heap);
		i++;
	}
	clean_heap_tree(&heap);
	return (sorted_array);
}
