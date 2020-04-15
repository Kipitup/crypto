/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tool.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 11:27:50 by amartino          #+#    #+#             */
/*   Updated: 2020/02/21 19:50:13 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

t_rb_tree	*get_parent(t_rb_tree *self)
{
	if (self == NULL || self->parent == NULL)
		return (NULL);
	else
		return (self->parent);
}

t_rb_tree	*get_grand_parent(t_rb_tree *self)
{
	return (get_parent(get_parent(self)));
}

t_rb_tree	*get_sibling(t_rb_tree *self)
{
	t_rb_tree	*node;

	node = get_parent(self);
	if (node != NULL)
	{
		if (node->left == self)
			node = node->right;
		else
			node = node->left;
	}
	return (node);
}

t_rb_tree	*get_uncle(t_rb_tree *self)
{
	return (get_sibling(get_parent(self)));
}

t_rb_tree	*get_root(t_rb_tree *node)
{
	while (get_parent(node) != NULL)
		node = get_parent(node);
	return (node);
}

void		clean_rb_tree(t_rb_tree **root)
{
	if (*root == NULL)
		return ;

	clean_rb_tree(&((*root)->right));

	clean_rb_tree(&((*root)->left));

	ft_memdel((void**)root);
}
