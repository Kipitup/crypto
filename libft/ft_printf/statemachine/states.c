/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 18:27:50 by amartino          #+#    #+#             */
/*   Updated: 2019/09/20 12:15:12 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int8_t		string(t_state_machine *ptf, char *input, va_list *arg_pf)
{
	(void)arg_pf;
	if (*input == CONVERSION_SIGN)
		ptf->state = ST_FLAGS;
	else if (*input == OPEN_BRACKET)
	{
		ptf->state = ST_COLOR;
		return (0);
	}
	else if (*input == '\0')
	{
		ptf->state = ST_BUFFER;
		return (0);
	}
	else if (vct_addchar(ptf->output, *input) == FAILURE)
		ptf->state = ST_ERROR;
	return (1);
}

int8_t		flags(t_state_machine *ptf, char *input, va_list *arg_pf)
{
	static const char	*flags[NB_OF_FLAGS] = {HH, LL, H, L, L_MAJ, PLUS, MINUS,
		HASH, ZERO, SPACE, POINT, J, Z};
	size_t				len;
	uint8_t				i;

	(void)arg_pf;
	i = 0;
	while (i < NB_OF_FLAGS)
	{
		len = i < 2 ? 2 : 1;
		if (ft_strnequ(flags[i], input, len) == TRUE)
		{
			if (i < NB_OF_MODIFIER)
				ptf->option &= ~ALL_MOD;
			ptf->option |= (1 << i);
			return (flags[i] == POINT ? is_precision(ptf, input + 1, arg_pf)
																		: len);
		}
		i++;
	}
	if ((len = is_width(ptf, input, arg_pf)) > 0)
		return ((int8_t)len);
	ptf->state = ST_CONVERSION;
	return (FAILURE);
}

int8_t		conversion(t_state_machine *ptf, char *input, va_list *arg_pf)
{
	static char *convs[NB_OF_CONVS] = {C, S, P, D, I, O, U, X, X_MAJ, F, R, B};
	uint8_t		i;

	(void)arg_pf;
	i = 0;
	while (i < NB_OF_CONVS)
	{
		if (ft_strnequ(convs[i], input, 1) == TRUE)
			break ;
		i++;
	}
	ptf->option |= ((1 << i) << 16);
	ptf->state = ST_BUFFER;
	return (0);
}

int8_t		buffer(t_state_machine *ptf, char *input, va_list *arg_pf)
{
	t_flag		flag;

	if (*input == '\0')
	{
		write(ptf->fd, vct_getstr(ptf->output), vct_len(ptf->output));
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

int8_t		color(t_state_machine *ptf, char *input, va_list *arg_pf)
{
	t_vector	*vector;
	int8_t		i;

	i = 0;
	input++;
	(void)arg_pf;
	if ((vector = init_colors()) == NULL)
	{
		ptf->state = ST_ERROR;
		return (0);
	}
	if (input[i] != 'c' || input[i + 1] != '_')
	{
		if (vct_addchar(ptf->output, OPEN_BRACKET) == FAILURE)
			ptf->state = ST_ERROR;
		ptf->state = ST_STRING;
		return (1);
	}
	while (input[i] != CLOSE_BRACKET)
		i++;
	search_color(ptf, vector, input, i);
	vct_del(&vector);
	ptf->state = ST_STRING;
	return (i + NB_OF_BRACKET);
}
