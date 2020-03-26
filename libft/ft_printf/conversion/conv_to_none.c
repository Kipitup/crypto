/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_to_none.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 14:33:16 by amartino          #+#    #+#             */
/*   Updated: 2019/09/20 11:32:29 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_vector		*conv_to_none(char input, t_flag *flag)
{
	t_vector	*vector;
	t_vector	*to_be_joined;

	vector = vct_new(flag->width);
	to_be_joined = vct_new(0);
	cancel_flag_for_none_conv(flag);
	if (to_be_joined != NULL)
		if ((vct_addchar(to_be_joined, input)) == FAILURE)
			vct_del(&to_be_joined);
	if (to_be_joined != NULL)
	{
		if ((apply_padding_flag(vector, flag, to_be_joined)) == FAILURE)
			vct_del(&vector);
		vct_del(&to_be_joined);
	}
	else
		vct_del(&vector);
	return (vector);
}
