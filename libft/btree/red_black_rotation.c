/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_rotation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 17:33:33 by amartino          #+#    #+#             */
/*   Updated: 2020/02/21 23:18:33 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

/*
** If u want to understand rotation: https://www.youtube.com/watch?v=95s3ndZRGbk
*/

void	left_rotate(t_rb_tree *old_root)
{
	t_rb_tree	*parent;
	t_rb_tree	*new_root;

	parent = get_parent(old_root);
	new_root = old_root->right;
	old_root->right = new_root->left;
	new_root->left = old_root;
	old_root->parent = new_root;

	if (old_root->right != NULL)
		old_root->right->parent = old_root;

	if (parent != NULL)
	{
		if (parent->right == old_root)
			parent->right = new_root;
		else
			parent->left = new_root;
		new_root->parent = parent;
	}
	else
		new_root->parent = NULL;
}

void	right_rotate(t_rb_tree *old_root)
{
	t_rb_tree	*parent;
	t_rb_tree	*new_root;

	parent = get_parent(old_root);
	new_root = old_root->left;
	old_root->left = new_root->right;
	new_root->right = old_root;
	old_root->parent = new_root;

	if (old_root->left != NULL)
		old_root->left->parent = old_root;

	if (parent != NULL)
	{
		if (parent->left == old_root)
			parent->left = new_root;
		else
			parent->right = new_root;
		new_root->parent = parent;
	}
	else
		new_root->parent = NULL;
}
