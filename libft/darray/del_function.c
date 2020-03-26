/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <a.martino@sutdent.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 12:14:10 by amartino          #+#    #+#             */
/*   Updated: 2020/03/10 19:18:17 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "darray.h"
#include "libft.h"
#include "hashmap.h"
#include "vector.h"

void	del_hashmap_node(void *content)
{
	t_hashnode *node;
	
	node = (t_hashnode*)content;
	if (content != NULL)
	{
		free(node->key);
		free(node->data);
		node->key = NULL;
		node->data = NULL;
		free(node);
	}
}

void	del_vector(void *content)
{
	t_vector	*vector;

	vector = (t_vector*)content;
	if (vector != NULL && vector->str != NULL)
	{		
		ft_strdel(&vector->str);
		free(vector);
	}
}
