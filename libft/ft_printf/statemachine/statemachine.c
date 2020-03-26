/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   statemachine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 17:37:23 by fkante            #+#    #+#             */
/*   Updated: 2019/09/20 11:50:54 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t		parser(t_state_machine *ptf, char *input, va_list *arg_pf)
{
	static t_statefunc	parser[5] = {string, flags, conversion, buffer, color};
	int8_t				scale;

	while (ptf->state != ST_END && ptf->state != ST_ERROR)
	{
		if ((scale = parser[ptf->state](ptf, input, arg_pf)) != FAILURE)
			input += scale;
	}
	return (ptf->state == ST_ERROR ? FAILURE : vct_len(ptf->output));
}
