/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_remove_order.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 18:55:35 by amartino          #+#    #+#             */
/*   Updated: 2020/03/01 18:48:54 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

void		delete_case_6(t_rb_tree *node)
{
	t_rb_tree	*sibling;

	ft_printf("delete case 6\n");
	sibling = get_sibling(node);
    sibling->color = node->parent->color;
    node->parent->color = BLACK;
    if (node == node->parent->left)
	{
      sibling->right->color = BLACK;
      left_rotate(node->parent);
    }
	else
	{
      sibling->left->color = BLACK;
      right_rotate(node->parent);
    }
}

static void		delete_case_5(t_rb_tree *node, t_rb_tree *sibling)
{
	uint8_t		s_child_r_color;
	uint8_t		s_child_l_color;

	s_child_r_color = (sibling->right != NULL) ? sibling->right->color : BLACK;
	s_child_l_color = (sibling->left != NULL) ? sibling->left->color : BLACK;
	if (sibling->color == BLACK)
	{
		if ((node == node->parent->left) && (s_child_r_color == BLACK)
				&& (s_child_l_color == RED))
		{
			ft_printf("delete case 5 right\n");
			sibling->color = RED;
			if (sibling->left != NULL)
				sibling->left->color = BLACK;
			right_rotate(sibling);
		}
		else if ((node == node->parent->right) && (s_child_l_color == BLACK)
				&& (s_child_r_color == RED))
		{
			ft_printf("delete case 5 left\n");
			sibling->color = RED;
			if (sibling->left != NULL)
				sibling->left->color = BLACK;
			left_rotate(sibling);
			ft_printf("finish case 5\n");
		}
	}
	delete_case_6(node);
}

static void		delete_case_4(t_rb_tree *node, t_rb_tree *sibling)
{
	uint8_t		s_child_r_color;
	uint8_t		s_child_l_color;

	s_child_r_color = (sibling->right != NULL) ? sibling->right->color : BLACK;
	s_child_l_color = (sibling->left != NULL) ? sibling->left->color : BLACK;
	if ((node->parent->color == RED) && (sibling->color == BLACK)
			&& (s_child_r_color == BLACK) && (s_child_l_color == BLACK))
	{
		ft_printf("delete case 4\n");
		sibling->color = RED;
		node->parent->color = BLACK;
	}
	else
		delete_case_5(node, sibling);
}

static void		delete_case_3(t_rb_tree *node, t_rb_tree *sibling)
{
	uint8_t		s_child_r_color;
	uint8_t		s_child_l_color;

	s_child_r_color = (sibling->right != NULL) ? sibling->right->color : BLACK;
	s_child_l_color = (sibling->left != NULL) ? sibling->left->color : BLACK;
	if ((node->parent->color == BLACK) && (sibling->color == BLACK)
			&& (s_child_r_color == BLACK) && (s_child_l_color == BLACK))
	{
		ft_printf("delete case 3\n");
		sibling->color = RED;
		delete_case_1(node->parent);
	}
	else
		delete_case_4(node, sibling);
}

static void		delete_case_2(t_rb_tree *node, t_rb_tree *sibling)
{
	if (sibling->color == RED)
	{
		ft_printf("delete case 2\n");
		node->parent->color = RED;
		sibling->color = BLACK;
		if (node == node->parent->left)
			left_rotate(node->parent);
		else
			right_rotate(node->parent);
	}
	delete_case_3(node, sibling);
}

/*
** The node is the new root, we are done
*/
void		delete_case_1(t_rb_tree *node)
{
	t_rb_tree	*sibling;

	if (get_parent(node) != NULL)
	{
		ft_printf("delete case 1\n");
		sibling = get_sibling(node);
		if (sibling !=  NULL)
			delete_case_2(node, sibling);
	}
}
