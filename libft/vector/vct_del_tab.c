/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_clean_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 20:25:40 by fkante            #+#    #+#             */
/*   Updated: 2020/03/11 21:02:14 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void			vct_del_tab_content(t_vector **vct_tab)
{
	size_t	i;

	i = 0;
	while (vct_tab[i] != NULL)
	{
		vct_del(&vct_tab[i]);
		i++;
	}
	vct_del(&vct_tab[i]);
}

void			vct_del_tab(t_vector ***vct_tab)
{
	vct_del_tab_content(*vct_tab);
	ft_memdel((void**)vct_tab);
}
