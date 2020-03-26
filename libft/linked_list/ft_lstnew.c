/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 15:18:30 by fkante            #+#    #+#             */
/*   Updated: 2019/05/08 13:42:14 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list_new;

	if (!(list_new = malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		list_new->content = NULL;
		list_new->content_size = 0;
	}
	else
	{
		if (!(list_new->content = (void*)malloc(content_size)))
		{
			free(list_new);
			return (NULL);
		}
		list_new->content = ft_memmove(list_new->content,
				content, content_size);
		list_new->content_size = content_size;
	}
	list_new->next = NULL;
	return (list_new);
}
