/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 16:29:13 by fkante            #+#    #+#             */
/*   Updated: 2019/11/28 16:09:31 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int8_t		init_state_machine(t_state_machine *ptf, int fd)
{
	ft_bzero(ptf, sizeof(t_state_machine));
	ptf->state = ST_STRING;
	if (fd >= 0)
		ptf->fd = fd;
	else
		return (FAILURE);
	ptf->output = vct_new(0);
	if (ptf->output == NULL)
		return (FAILURE);
	return (SUCCESS);
}

void		init_flags(t_state_machine *ptf, t_flag *flag)
{
	ft_bzero(flag, sizeof(t_flag));
	flag->width = ptf->width;
	flag->precision = ptf->precision;
	flag->option = ptf->option;
}

t_vector	*init_colors(void)
{
	t_vector	*vector;

	vector = vct_newstr("	c_black\033[0;30m		c_b_black\033[1;30m\
							c_bb_black\033[1;40m	c_red\033[0;31m\
							c_b_red\033[1;31m		c_bb_red\033[1;41m\
							c_green\033[0;32m		c_b_green\033[1;32m\
							c_bb_green\033[1;42m	c_yellow\033[0;33m\
							c_b_yellow\033[1;33m	c_bb_yellow\033[1;43m\
							c_blue\033[0;34m		c_b_blue\033[1;34m\
							c_bb_blue\033[1;44m		c_magenta\033[0;35m\
							c_b_magenta\033[1;35m	c_bb_magenta\033[1;45m\
							c_cyan\033[0;36m		c_b_cyan\033[1;36m\
							c_bb_cyan\033[1;46m		c_white\033[0;37m\
							c_b_white\033[1;37m		c_bb_white\033[1;47m\
							c_end\033[0m");
	return (vector);
}
