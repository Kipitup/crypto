/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   statemachine_asprintf.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 17:37:23 by fkante            #+#    #+#             */
/*   Updated: 2019/09/20 12:24:04 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int8_t		buffer_as_pf(t_state_machine *ptf, char *input, va_list *arg_pf)
{
	t_flag		flag;

	if (*input == '\0')
	{
		ptf->state = ST_END;
		return (0);
	}
	check_and_cancel_flag(ptf);
	init_flags(ptf, &flag);
	if (convert(ptf, &flag, input, arg_pf) == FAILURE)
		ptf->state = ST_ERROR;
	else
		ptf->state = ST_STRING;
	ptf->option = 0;
	ptf->width = 0;
	ptf->precision = 0;
	return (1);
}

ssize_t		parser_aspf(t_state_machine *ptf, char *input, va_list *arg_pf)
{
	static t_statefunc	parser[5] = {string, flags, conversion, buffer_as_pf,
										color};
	int8_t				scale;

	while (ptf->state != ST_END && ptf->state != ST_ERROR)
	{
		if ((scale = parser[ptf->state](ptf, input, arg_pf)) != FAILURE)
			input += scale;
	}
	return (ptf->state == ST_ERROR ? FAILURE : vct_len(ptf->output));
}
