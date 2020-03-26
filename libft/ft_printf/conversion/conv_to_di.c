/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_to_di.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 18:51:01 by fkante            #+#    #+#             */
/*   Updated: 2020/01/20 11:42:19 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int8_t			conv_di(t_vector *vector, t_flag *flag, t_vector *nb_itoa)
{
	int	ret;

	ret = FAILURE;
	if (vector != NULL && nb_itoa != NULL)
		ret = apply_padding_flag(vector, flag, nb_itoa);
	return (ret);
}

t_vector		*conv_to_di(va_list *arg_pf, t_flag *flag)
{
	t_vector	*vector;
	t_vector	*nb_itoa;
	char		*str_itoa;
	int64_t		nbr;

	nbr = va_arg(*arg_pf, int64_t);
	vector = vct_new(flag->width);
	nb_itoa = vct_new(0);
	str_itoa = NULL;
	cancel_flag_for_numeric_conv(flag);
	nbr = apply_modifier_di(nbr, flag->option);
	if (flag->option & FLAG_Z || flag->option & FLAG_J)
		nbr = apply_modifier_zj(nbr, flag->option);
	if ((str_itoa = ft_itoa_base(nbr, 10)) == NULL)
		vct_del(&nb_itoa);
	if (nb_itoa != NULL)
		if ((vct_addstr(nb_itoa, str_itoa)) == FAILURE)
			vct_del(&nb_itoa);
	ft_strdel(&str_itoa);
	if ((conv_di(vector, flag, nb_itoa)) == FAILURE)
		vct_del(&vector);
	vct_del(&nb_itoa);
	return (vector);
}
