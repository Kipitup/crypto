/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjacency_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 15:54:26 by amartino          #+#    #+#             */
/*   Updated: 2020/03/11 14:54:05 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"
#include "libft.h"

static t_adj_node	*new_adj_list_node(size_t dest)
{
	t_adj_node		*new_node;

	new_node = ft_memalloc(sizeof(t_adj_node));
	if (new_node != NULL)
		new_node->dest = dest;
	return (new_node);
}

uint8_t				does_link_exist(t_graph *graph, size_t src, size_t dest)
{
	t_adj_node	*node_src;
	uint8_t		ret;

	ret = FALSE;
	if (graph != NULL)
	{
		node_src = graph->array[src].head;
		while (node_src != NULL)
		{
			if (node_src->dest == dest)
			{
				ret = TRUE;
				break;
			}
			node_src = node_src->next;
		}
	}
	return (ret);
}

int8_t				add_edge(t_graph *graph, size_t src, size_t dest)
{
	t_adj_node		*new_node;

	if (graph == NULL)
		return (FAILURE);
	new_node = new_adj_list_node(dest);
	if (new_node == NULL)
		return (FAILURE);
	new_node->next = graph->array[src].head;
	graph->array[src].head = new_node;

	new_node = new_adj_list_node(src);
	if (new_node == NULL)
		return (FAILURE);
	new_node->next = graph->array[dest].head;
	graph->array[dest].head = new_node;
	return (SUCCESS);
}

t_graph				*init_graph(size_t size)
{
	t_graph		*graph;

	graph = ft_memalloc(sizeof(t_graph));
	if (graph != NULL)
	{
		graph->size = size;
		graph->array = ft_memalloc(size * sizeof(t_adj_list));
		if (graph->array == NULL)
			ft_memdel((void**)&graph);
	}
	return (graph);
}
