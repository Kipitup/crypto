/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 10:34:22 by fkante            #+#    #+#             */
/*   Updated: 2019/04/26 11:52:05 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *lst_old;
	t_list *start;
	t_list *lst_new;

	if (lst != NULL && f != NULL)
	{
		if (!(start = f(lst)))
			return (NULL);
		lst_new = start;
		lst_old = lst->next;
		while (lst_old->next != NULL)
		{
			if (!(lst_new->next = f(lst_old)))
				return (NULL);
			lst_new = lst_new->next;
			lst_old = lst_old->next;
		}
		if (!(lst_new->next = f(lst_old)))
			return (NULL);
		lst_new->next->next = NULL;
		return (start);
	}
	return (NULL);
}
