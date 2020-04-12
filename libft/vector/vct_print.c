/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:00:45 by amartino          #+#    #+#             */
/*   Updated: 2020/04/03 17:44:26 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/*
**	Print the vector. Return the number of byte written or FAILURE if an error
**	occur.
*/
ssize_t		vct_print(t_vector *vector)
{
	ssize_t		ret;

	ret = FAILURE;
	if (vector != NULL && vector->str != NULL)
		ret = write(1, vector->str, vector->len);
	return (ret);
}
