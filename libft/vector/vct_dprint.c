/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_dprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartinod <a.martino@sutdent.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 17:36:57 by amartinod         #+#    #+#             */
/*   Updated: 2020/04/03 17:42:17 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/*
**	Print the vector on the given fd. Return the number of byte written or
**	FAILURE if an error occur.
*/
ssize_t		vct_dprint(int fd, t_vector *vector)
{
	ssize_t		ret;

	ret = FAILURE;
	if (fd >= 0 && vector != NULL && vector->str != NULL)
		ret = write(fd, vector->str, vector->len);
	return (ret);
}
