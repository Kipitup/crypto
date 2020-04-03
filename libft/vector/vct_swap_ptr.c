/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_swap_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartinod <a.martino@sutdent.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 11:56:22 by amartinod         #+#    #+#             */
/*   Updated: 2020/04/03 11:58:44 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/*
**	Swap both pointer content.
*/

void		vct_swap_ptr(t_vector **left, t_vector **right)
{
	t_vector *tmp;

	tmp = *right;
	*right = *left;
	*left = tmp;
}
