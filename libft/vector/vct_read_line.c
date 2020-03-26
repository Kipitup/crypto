/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_read_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 15:08:41 by amartino          #+#    #+#             */
/*   Updated: 2020/03/12 14:33:43 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/*
**	Read the next line from the given fd.
*/
static int8_t	parse_line(t_vector *vector, t_vector **line, uint8_t the_end)
{
	ssize_t	index;
	int8_t	ret;

	ret = FALSE;
 	index = vct_chr(vector, '\n');
	if (index >= 0)
	{
		ret = TRUE;
		*line = vct_sub(vector, START, (size_t)index);
		if (*line == NULL)
			ret = FAILURE;
		if (vct_pop_from(vector, ((size_t)index + 1), START) == FAILURE)
			ret = FAILURE;
	}
	else if (the_end == TRUE)
	{
		ret = TRUE;
		*line = vct_dup(vector);
		if (*line == NULL)
			ret = FAILURE;
		vct_pop(vector, vector->len);
	}
	return (ret);
}

static int8_t	read_file(t_vector *vector, t_vector **line, const int fd)
{
	ssize_t		ret;
	char		buff[BUFF_SIZE + 1];

	while ((ret = read(fd, &buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (vct_addnstr(vector, buff, (size_t)ret) == FAILURE)
			return (FAILURE);
		if (vct_chr(vector, '\n') >= 0)
			return (parse_line(vector, line, FALSE));
	}
	if (ret == SUCCESS && vector->len > 0)
		return (parse_line(vector, line, TRUE));
	return ((int8_t)ret);
}

int8_t			vct_read_line(const int fd, t_vector **line)
{
	static t_vector	*vector = NULL;
	ssize_t			ret;

	ret = FALSE;
	if (fd < 0)
	{
		if (fd == CLEANUP)
			vct_del(&vector);
		return (fd == CLEANUP ? SUCCESS : FAILURE);
	}
	if (vector == NULL)
	{
		vector = vct_new(DEFAULT_VCT_SIZE);
		if (vector == NULL)
			return (FAILURE);
	}
	if (vct_len(vector) > 0)
		ret = parse_line(vector, line, FALSE);
	if (ret == FALSE)
		ret = read_file(vector, line, fd);
	if (ret == FAILURE)
		vct_del(&vector);
	return (ret);
}
