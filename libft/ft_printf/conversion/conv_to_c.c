/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_to_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 17:55:03 by fkante            #+#    #+#             */
/*   Updated: 2019/09/19 15:37:30 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_vector	*conv_to_c(va_list *arg_pf, t_flag *flag)
{
	t_vector	*vector;
	t_vector	*to_be_joined;
	char		c;

	vector = vct_new(flag->width);
	cancel_flag_for_other_conv(flag);
	c = (char)va_arg(*arg_pf, int);
	c = apply_modifier_u((int64_t)c, flag->option);
	to_be_joined = vct_new(0);
	if (to_be_joined != NULL)
		if ((vct_addchar(to_be_joined, c)) == FAILURE)
			vct_del(&to_be_joined);
	if (to_be_joined != NULL)
	{
		if ((apply_padding_flag(vector, flag, to_be_joined)) == FAILURE)
			vct_del(&vector);
	}
	else
		vct_del(&vector);
	vct_del(&to_be_joined);
	return (vector);
}
