/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <a.martino@sutdent.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 19:06:02 by amartino          #+#    #+#             */
/*   Updated: 2020/03/11 10:22:24 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"
#include "ft_printf.h"

void	print_adj_list(t_graph *graph)
{
	t_adj_node	*node;
	size_t		i;

	i = 0;
	if (graph != NULL)
	{
		while (i < graph->size)
		{
			ft_printf("vertex %d\nhead", i);
			node = graph->array[i].head;
			while (node != NULL)
			{
				ft_printf(" -> %d", node->dest);
				node = node->next;
			}
			ft_printf("\n");
			i++;
		}
	}
}
