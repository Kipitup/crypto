/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 11:17:18 by amartino          #+#    #+#             */
/*   Updated: 2020/03/12 14:22:55 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"
#include <stdio.h>

/*
**	Recursively print the tree.

**	Index will usually start at 1, since index 0 is reserved for the HEAP SIZE.
**	deep variable start at 0. 
*/

void	print_heap_tree(t_heap *heap, size_t index, size_t deep)
{
	size_t		space;

	space = NB_OF_SPACE * deep;
	if ((int32_t)index > heap->array[HEAP_SIZE])
		return ;

	print_heap_tree(heap, get_right_child(index), deep + 1);

	// printf("\n");
    for (size_t i = 0; i < space; i++)
        printf(" ");
    printf("%d\n", heap->array[index]);

	print_heap_tree(heap, get_left_child(index), deep + 1);
}
