/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_and_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 11:05:11 by amartino          #+#    #+#             */
/*   Updated: 2019/09/20 10:20:12 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uint8_t		is_width(t_state_machine *ptf, char *input, va_list *arg_pf)
{
	int32_t	neg_prot;
	size_t	nb;

	nb = 0;
	if (ft_isdigit((int)input[0]) == TRUE)
		ptf->width = get_numbers(ptf, input, &nb);
	else if (input[0] == WILDCARD_SIGN)
	{
		if ((neg_prot = va_arg(*arg_pf, int64_t)) < 0)
		{
			neg_prot = ft_absolute(neg_prot);
			ptf->option |= FLAG_MINUS;
		}
		ptf->width = neg_prot;
		nb++;
	}
	return (nb);
}

uint8_t		is_precision(t_state_machine *ptf, char *input, va_list *arg_pf)
{
	int32_t	neg_prot;
	size_t	nb;

	nb = 0;
	if (ft_isdigit((int)input[0]) == TRUE)
		ptf->precision = get_numbers(ptf, input, &nb);
	else if (input[0] == WILDCARD_SIGN)
	{
		if ((neg_prot = va_arg(*arg_pf, int64_t)) < 0)
		{
			neg_prot = 0;
			ptf->option &= ~FLAG_POINT;
		}
		ptf->precision = neg_prot;
		nb++;
	}
	else
		ptf->precision = 0;
	return (nb + 1);
}

uint64_t	get_numbers(t_state_machine *ptf, char *input, size_t *count)
{
	uint64_t	nb;
	t_vector	*vector;

	nb = 0;
	vector = vct_new(0);
	if (vector == NULL)
		ptf->state = ST_ERROR;
	else
	{
		while (ft_isdigit((int)input[*count]) == TRUE)
		{
			if ((vct_addchar(vector, input[*count])) == FAILURE)
			{
				ptf->state = ST_ERROR;
				break ;
			}
			(*count)++;
		}
		nb = (uint64_t)ft_atoi(vector->str);
		vct_del(&vector);
	}
	return (nb);
}
