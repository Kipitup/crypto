/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_print_nl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:00:45 by amartino          #+#    #+#             */
/*   Updated: 2020/04/03 17:52:03 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/*
**	Print the vector and a new line. Return the number of byte written for the
**	vector only, without the new line or FAILURE if an error occur.
*/
ssize_t		vct_print_nl(t_vector *vector)
{
	ssize_t		ret;

	ret = FAILURE;
	if (vector != NULL && vector->str != NULL)
	{
		ret = write(1, vector->str, vector->len);
		write(1, "\n", 1);
	}
	return (ret);
}
