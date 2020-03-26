/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 16:04:57 by fkante            #+#    #+#             */
/*   Updated: 2019/11/17 15:33:56 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_strdup allocates memory to store the copy, and returns a pointer to it
** ft_strjoin allocates memory, concatenate s1 and s2 and returns a fresh
** string ended by '\0'
*/

static int8_t	strrest_with_newline(char **line, char **str_rest)
{
	char	*newline_position;
	char	*str_after_newline;

	newline_position = NULL;
	str_after_newline = NULL;
	if (*str_rest == NULL)
		return (FAILURE);
	newline_position = ft_strchr(*str_rest, '\n');
	if (newline_position == NULL)
	{
		*line = ft_strdup(*str_rest);
		ft_strdel(str_rest);
		return (FAILURE);
	}
	if (*(newline_position + 1) != '\0')
		str_after_newline = ft_strdup(newline_position + 1);
	*newline_position = '\0';
	*line = ft_strdup(*str_rest);
	ft_strdel(str_rest);
	*str_rest = str_after_newline;
	return (SUCCESS);
}

static int		read_buffer(const int fd, char **line, char **str_rest)
{
	char		buff[BUFF_SIZE + 1];
	char		*newline_position;
	char		*leaks;
	ssize_t		read_return;

	while ((read_return = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[read_return] = '\0';
		leaks = *line;
		if ((newline_position = ft_strchr(buff, '\n')) == NULL)
		{
			*line = ft_strjoin(*line, buff);
			ft_strdel(&leaks);
			continue ;
		}
		if (*(newline_position + 1) != '\0')
			*str_rest = ft_strdup(newline_position + 1);
		*newline_position = '\0';
		*line = ft_strjoin(*line, buff);
		ft_strdel(&leaks);
		return (1);
	}
	if (read_return == FAILURE)
		return (FAILURE);
	return ((*line == NULL && *str_rest == NULL) ? 0 : 1);
}

/*
** 1st: check for errors (empty line, number of the fd invalid)
** 2nd: check if we have already data in our static var str_rest
** 3rd: if str_rest exist, we resume from the position it had in the file
**      if not, we read from the fd the specific nbr of bytes "BUFF_SIZE"
** 4th: we concatenate what we have in the stack with what we read in the heap
** here is another read on vm and heap:
** https://blog.holbertonschool.com/hack-the-virtual-memory-c-strings-proc/
** TO BE ADDED: Protection for the BUFF_SIZE max
*/

int				get_next_line(const int fd, char **line)
{
	static char	*str_rest[FD_LIMIT];

	if (fd < 0 || fd > FD_LIMIT || line == NULL)
		return (FAILURE);
	if (str_rest[fd] == NULL || str_rest[fd][0] == '\0')
		*line = NULL;
	if (strrest_with_newline(line, &str_rest[fd]) == SUCCESS)
		return (1);
	return (read_buffer(fd, line, &str_rest[fd]));
}
