/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_insert_order.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 23:20:46 by amartino          #+#    #+#             */
/*   Updated: 2020/02/23 18:55:18 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

void		node_is_root(t_rb_tree *root)
{
	root->color = BLACK;
}

void		uncle_is_red(t_rb_tree *node)
{
	get_parent(node)->color = BLACK;
	get_uncle(node)->color = BLACK;
	get_grand_parent(node)->color = RED;
	repair_tree(get_grand_parent(node));
}

t_rb_tree	*form_a_line(t_rb_tree *node)
{
	t_rb_tree	*parent;
	t_rb_tree	*grand_parent;

	parent = get_parent(node);
	grand_parent = get_grand_parent(node);
	if (node == parent->left && parent == grand_parent->right)
	{
		right_rotate(parent);
		node = node->right;
	}
	else if (node == parent->right && parent == grand_parent->left)
	{
		left_rotate(parent);
		node = node->left;
	}
	return (node);
}

void		uncle_is_black(t_rb_tree *node)
{
	t_rb_tree	*parent;
	t_rb_tree	*grand_parent;

	node = form_a_line(node);
	parent = get_parent(node);
	grand_parent = get_grand_parent(node);
	if (node == parent->right)
		left_rotate(grand_parent);
	else
		right_rotate(grand_parent);
	parent->color = BLACK;
	grand_parent->color = RED;
}

void	repair_tree(t_rb_tree *node)
{
	t_rb_tree	*parent;
	t_rb_tree	*uncle;

	if (node != NULL)
	{
		parent = get_parent(node);
		uncle = get_uncle(node);
		if (parent == NULL)
			node_is_root(node);
		else if (parent->color == BLACK)
			return ;
		else if (uncle != NULL && uncle->color == RED)
			uncle_is_red(node);
		else
			uncle_is_black(node);
	}
}
