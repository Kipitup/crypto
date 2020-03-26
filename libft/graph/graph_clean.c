/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_clean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <a.martino@sutdent.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 19:05:43 by amartino          #+#    #+#             */
/*   Updated: 2020/03/09 19:14:41 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"
#include "libft.h"

void	clean_recurse(t_adj_node **node)
{
	if (node != NULL && *node != NULL)
	{
		while ((*node)->next != NULL)
			clean_recurse(&((*node)->next));
		ft_memdel((void**)node);
	}
}

void	clean_graph(t_graph **graph)
{
	size_t		i;

	i = 0;
	if (graph != NULL && *graph != NULL)
	{
		while (i < (*graph)->size)
		{
			clean_recurse(&((*graph)->array[i].head));
			i++;
		}
		ft_memdel((void**)&((*graph)->array));
		ft_memdel((void**)graph);
	}
}
