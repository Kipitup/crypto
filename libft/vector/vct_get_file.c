/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_get_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartinod <a.martino@sutdent.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 09:47:59 by amartinod         #+#    #+#             */
/*   Updated: 2020/04/07 10:25:23 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/*
**	Read the file from the given fd and return it in a vector
*/
t_vector	*vct_get_file(int fd)
{
	t_vector	*file;
	t_vector	*line;
	int8_t		ret;

	line = NULL;
	file = vct_new(DEFAULT_VCT_SIZE);
	while ((ret = vct_read_line(fd, &line)) >= 0)
	{
		if (ret > 0)
			if (vct_addchar(line, '\n') == FAILURE)
				ret = FAILURE;
		if (ret != FAILURE)
			if (vct_cat(file, line) == FAILURE)
				ret = FAILURE;
		vct_del(&line);
		if (ret == FAILURE || ret == SUCCESS)
			break ;
	}
	vct_read_line(CLEANUP, &line);
	if (ret == FAILURE)
		vct_del(&file);
	return (file); 
}
