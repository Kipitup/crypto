/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_to_ox.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 09:39:55 by fkante            #+#    #+#             */
/*   Updated: 2020/01/20 11:42:40 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int8_t			conv_ox(t_vector *vector, t_flag *flag, t_vector *nb_itoa)
{
	int	ret;

	ret = FAILURE;
	if (vector != NULL && nb_itoa != NULL)
		ret = apply_padding_flag(vector, flag, nb_itoa);
	return (ret);
}

t_vector		*conv_to_ox(va_list *arg_pf, t_flag *flag)
{
	t_vector	*vector;
	t_vector	*nb_itoa;
	char		*str_itoa;
	uint64_t	nbr;

	nbr = va_arg(*arg_pf, uint64_t);
	vector = vct_new(flag->width);
	nb_itoa = vct_new(0);
	str_itoa = NULL;
	cancel_flag_for_other_conv(flag);
	if (flag->option & FLAG_Z || flag->option & FLAG_J)
		nbr = apply_modifier_zj(nbr, flag->option);
	else
		nbr = apply_modifier_oxx_maj(nbr, flag->option);
	if ((str_itoa = ft_ox_itoa_base(nbr, (flag->option & CONV_O ? 8 : 16),
			flag->option)) == NULL)
		vct_del(&nb_itoa);
	if (nb_itoa != NULL)
		if ((vct_addstr(nb_itoa, str_itoa)) == FAILURE)
			vct_del(&nb_itoa);
	ft_strdel(&str_itoa);
	if ((conv_ox(vector, flag, nb_itoa)) == FAILURE)
		vct_del(&vector);
	vct_del(&nb_itoa);
	return (vector);
}
