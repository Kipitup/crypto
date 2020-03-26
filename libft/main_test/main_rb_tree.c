/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_rb_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 08:55:24 by amartino          #+#    #+#             */
/*   Updated: 2020/03/01 19:34:39 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

int		main()
{
	int32_t		array[22] = {5, 8, 15, 12, 20, 9, 13, 23, 10, 23, 34, -2, 0, -30, 27, 5, -5, 1, 17, 19, -8, 14};
	t_rb_tree	*root;

	root = red_black_tree(array, 22);
	root = delete(root, 19);
	print_rb_tree(root, 0);
	clean_rb_tree(&root);
	return (SUCCESS);
}
