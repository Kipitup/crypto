/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_print_nl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:00:45 by amartino          #+#    #+#             */
/*   Updated: 2020/03/28 18:01:40 by ezalos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/*
**	Print the vector and a new line
*/

void	vct_print_nl(t_vector *vector)
{
	if (vector != NULL && vector->str != NULL)
	{
		ft_printf("[%d]", vector->len);
		write(1, vector->str, vector->len);
		write(1, "\n", 1);
	}
}
