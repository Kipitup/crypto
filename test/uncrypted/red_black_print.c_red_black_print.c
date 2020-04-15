/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 11:17:18 by amartino          #+#    #+#             */
/*   Updated: 2020/02/23 12:04:37 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

/*
**	Recursively print the tree.
**
**	The variable deep start at 0.
*/

void	padding_before(t_rb_tree *node, size_t space)
{
	t_rb_tree	*parent;
	size_t 		i;

	i = 0;
	parent = get_parent(node);
	while (i < space)
	{
		printf(" ");
		i++;
	}
	if (parent != NULL)
		(parent->left == node) ? printf("╰─ ") : printf("╭─ ");
}

void	padding_after(t_rb_tree *node)
{
	size_t 		i;
	size_t		padding;

	if (node->left != NULL || node->right != NULL)
	{
		padding = NB_OF_SPACE - ft_nb_unitlen(node->key) - 4;
		i = 0;
		while (i < padding)
		{
			printf("─");
			i++;
		}
		if (get_root(node) == node)
			printf("───");
		printf("┤");
	}
	printf("\n");
}

void	print_rb_tree(t_rb_tree *node, size_t deep)
{
	if (node == NULL)
		return ;
	print_rb_tree(node->right, deep + 1);

	padding_before(node, (deep * NB_OF_SPACE));
	if (node->color == RED)
    	printf("\033[0;31m%d \033[00m", node->key);
	else
		printf("\033[37m%d \033[00m", node->key);
	padding_after(node);

	print_rb_tree(node->left, deep + 1);
}
