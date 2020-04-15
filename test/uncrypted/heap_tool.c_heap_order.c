/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_tool.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 10:52:13 by amartino          #+#    #+#             */
/*   Updated: 2020/03/12 14:23:14 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

size_t	get_heap_parent(size_t index)
{
	return (index == 1 ? 1 : index / 2);
}

size_t	get_left_child(size_t index)
{
	return (index * 2);
}

size_t	get_right_child(size_t index)
{
	return ((index * 2) + 1);
}

void	clean_heap_tree(t_heap **heap)
{
	ft_memdel((void**)&((*heap)->array));
	ft_memdel((void**)heap);
}

size_t	deepness(size_t max)
{
	size_t	deep;

	deep = 0;
	while (max != 0)
	{
		max = max / 2;
		deep++;
	}
	return (deep);
}
