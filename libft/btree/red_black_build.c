/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_build.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 10:42:46 by amartino          #+#    #+#             */
/*   Updated: 2020/03/12 14:18:02 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

static void		insert_recurse(t_rb_tree *root, t_rb_tree *new_node)
{
	if (root != NULL && new_node != NULL)
	{
		if (root->key > new_node->key)
		{
			if (root->left != NULL)
				insert_recurse(root->left, new_node);
			else
			{
				root->left = new_node;
				new_node->parent = root;
			}
		}
		else
		{
			if (root->right != NULL)
				insert_recurse(root->right, new_node);
			else
			{
				root->right = new_node;
				new_node->parent = root;
			}
		}
	}
}

t_rb_tree		*init_node(int32_t key)
{
	t_rb_tree	*new_node;

	new_node = ft_memalloc(sizeof(t_rb_tree));
	if (new_node != NULL)
	{
		new_node->key = key;
		new_node->color = RED;
	}
	return (new_node);
}

t_rb_tree		*insert(t_rb_tree *root, int32_t key)
{
	t_rb_tree	*new_node;

	new_node = init_node(key);
	if (new_node == NULL)
		clean_rb_tree(&root);
	insert_recurse(root, new_node);
	repair_tree(new_node);
	root = get_root(new_node);
	return (root);
}

t_rb_tree		*red_black_tree(int32_t *array, size_t size)
{
	t_rb_tree	*root;
	size_t		i;

	i = 0;
	root = NULL;
	while (i < size)
	{
		root = insert(root, array[i]);
		i++;
	}
	return (root);
}
