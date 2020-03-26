/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_bzero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 17:05:32 by amartino          #+#    #+#             */
/*   Updated: 2019/09/03 17:13:05 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/*
**	Fill the allocated bloc with '\0'
*/

void			vct_bzero(t_vector *vector)
{
	if (vector != NULL && vector->str != NULL)
	{
		ft_bzero(vector->str, vector->size);
		vector->len = 0;
	}
}
