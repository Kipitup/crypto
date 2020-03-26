/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 16:25:10 by fkante            #+#    #+#             */
/*   Updated: 2019/05/08 13:41:02 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;

	while (alst != NULL && *alst != NULL && del)
	{
		del((*alst)->content, (*alst)->content_size);
		tmp = *alst;
		*alst = (*alst)->next;
		tmp->next = NULL;
		free(tmp);
		tmp = NULL;
	}
	alst = NULL;
}
