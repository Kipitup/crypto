/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_remove.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 15:40:53 by amartino          #+#    #+#             */
/*   Updated: 2020/03/01 19:37:01 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

static void			replace_node(t_rb_tree *node, t_rb_tree *child)
{
	child->parent = node->parent;
	if (node == node->parent->left)
		node->parent->left = child;
	else
		node->parent->right = child;
}

/*
** I first replace node with child. So in the second if, node's key is
** child's key. Note that the color did not changed.
*/
static void			delete_child(t_rb_tree *node)
{
	t_rb_tree	*child;

	child = (node->right == NULL) ? node->left : node->right;
	if (child != NULL)
		replace_node(node, child);
	else
		child = node;
	if (node->color == BLACK)
	{
		if (child->color == RED)
			child->color = BLACK;
		else
			delete_case_1(child);
	}
	print_rb_tree(get_root(node), 0);
	ft_printf("node->key %d\tnode color %d\nchild %d\t child color %d\n", node->key, node->color, child->key, child->color);
	free(node);
	node = NULL;
	// if (node == get_parent(node)->left)
	// 	ft_memdel((void**)&(get_parent(node)->left));
	// else
	// 	ft_memdel((void**)&(get_parent(node)->right));
}

static t_rb_tree	*swap_key_with_successor(t_rb_tree *node, int32_t key)
{
	t_rb_tree	*to_delete;
	t_rb_tree	*successor;

	while (key != node->key)
	{
		node = (key > node->key) ? node->right : node->left;
	}
	to_delete = node;
	successor = (node->right != NULL) ? node->right : node;
	while (successor->left != NULL)
	{
		successor = successor->left;
	}
	to_delete->key = successor->key;
	to_delete = successor;
	return (to_delete);
}

t_rb_tree			*delete(t_rb_tree *node, int32_t key)
{
	t_rb_tree	*to_delete;

	if (node != NULL)
	{
		to_delete = swap_key_with_successor(node, key);
		delete_child(to_delete);
		node = get_root(node);
	}
	return (node);
}
