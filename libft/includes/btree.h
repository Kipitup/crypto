/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 10:49:04 by amartino          #+#    #+#             */
/*   Updated: 2020/03/12 14:19:32 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BTREE_H
# define BTREE_H

#include "libft.h"
#include <stdio.h>

# define NB_OF_SPACE	10

/*
*****************************************************************************
**	Red-Black Tree is a self-balancing Binary Search Tree (BST)
**
**	Every node follows those  rules:
**	1. Node is either red or black.
**	2. The root and leaves (NIL) are black.
**	3. If a node is red, then his children are black.
**	4. All path from a node to its NIL descendants contain the same number of
**	   black nodes.
**
**	Every Red Black Tree with n nodes has height <= 2Log2(n+1)
*****************************************************************************
*/
typedef struct					s_rb_tree
{
	struct s_rb_tree	*parent;
	struct s_rb_tree	*left;
	struct s_rb_tree	*right;
	int32_t				key;
	uint8_t				color;
	char				padding[3];
}								t_rb_tree;

# define RED			0
# define BLACK			1

/*
*****************************************************************************
**	Heap tree is complete binary tree implementation for Priority Queue. (PQ)
**
**	I've choosen to implement it in a simple array. This is possible because
**	complete binary tree is a binary tree in which every level, except possibly
**	the last, is completely filled, and all nodes are as far left as possible.
**
**	Heap tree start at index 1. Index 0 store the HEAP SIZE
**
**	2 type of tree : - MAX_HEAP (0). Father greater than its children.
**					 - MIN_HEAP (1). Father less than its children.
**					 check the define above
**
**	Doc : https://s.42l.fr/heap_tree
*****************************************************************************
*/
typedef struct				s_heap
{
	int32_t				*array;
	uint8_t				type;
	char				padding[7];
}							t_heap;

# define HEAP_SIZE		0
# define ROOT			1
# define MAX_HEAP		0
# define MIN_HEAP		1

/*
** ############################################################################
** ############################### RED-BLACK ##################################
** ############################################################################
*/
t_rb_tree	*red_black_tree(int32_t *array, size_t size);
t_rb_tree	*insert(t_rb_tree *root, int32_t key);
t_rb_tree	*init_node(int32_t key);
void		repair_tree(t_rb_tree *node);
void		left_rotate(t_rb_tree *old_root);
void		right_rotate(t_rb_tree *old_root);
t_rb_tree	*delete(t_rb_tree *node, int32_t key);
void		delete_case_1(t_rb_tree *node);
t_rb_tree	*get_root(t_rb_tree *node);
t_rb_tree	*get_parent(t_rb_tree *self);
t_rb_tree	*get_grand_parent(t_rb_tree *self);
t_rb_tree	*get_sibling(t_rb_tree *self);
t_rb_tree	*get_uncle(t_rb_tree *self);
void		clean_rb_tree(t_rb_tree **root);
void		print_rb_tree(t_rb_tree *node, size_t deep);

/*
** ############################################################################
** ################################# HEAP #####################################
** ############################################################################
*/
t_heap		*heap_tree(int32_t *tab, size_t size, uint8_t type);
void		delete_root(t_heap *heap);
void		clean_heap_tree(t_heap **heap);
void 		is_parent_valid(t_heap *heap, size_t child);
void		heapify(t_heap *heap, size_t parent);
size_t		get_heap_parent(size_t index);
size_t		get_left_child(size_t index);
size_t		get_right_child(size_t index);
size_t		deepness(size_t max);
void		print_heap_tree(t_heap *heap, size_t index, size_t deep);

#endif
