/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_print_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 20:27:37 by fkante            #+#    #+#             */
/*   Updated: 2020/03/11 20:28:27 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	vct_print_tab(t_vector **tab)
{
	size_t	i;

	i = 0;
	if (tab != NULL)
	{
		while (tab[i] != NULL)
		{
			ft_printf("vector[%i] = ", i);
			vct_print(tab[i]);
			ft_printf("\n");
			i++;
		}
	}
}
