/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 15:51:11 by fkante            #+#    #+#             */
/*   Updated: 2020/03/11 21:03:51 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"


int		main(int ac, char **av)
{
	t_vector	*vector;
	t_vector	**vct_tab;

	(void)ac;
	vector = vct_newstr(av[1]);
	vct_tab = vct_split(vector, av[2][0]);
	vct_print_tab(vct_tab);
	vct_del_tab(&vct_tab);
	vct_del(&vector);
	return (0);
}
