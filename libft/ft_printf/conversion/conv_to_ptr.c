/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_to_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 11:54:54 by fkante            #+#    #+#             */
/*   Updated: 2020/01/20 11:42:35 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int8_t		apply_prefix(t_vector *vector, t_flag *flag, t_vector *nb_itoa)
{
	int	ret;

	ret = FAILURE;
	if (vector != NULL && nb_itoa != NULL)
	{
		if (flag->width >= vct_len(nb_itoa))
		{
			ret = vct_pushstr(nb_itoa, "0x");
			if (ret == SUCCESS)
				ret = apply_padding_flag(vector, flag, nb_itoa);
		}
		else
		{
			if (nb_itoa != NULL)
			{
				ret = apply_padding_flag(vector, flag, nb_itoa);
				if (ret == SUCCESS)
					ret = vct_pushstr(vector, "0x");
			}
		}
	}
	return (ret == FAILURE ? FAILURE : SUCCESS);
}

t_vector	*conv_to_ptr(va_list *arg_pf, t_flag *flag)
{
	t_vector	*vector;
	t_vector	*nb_itoa;
	uint64_t	*address;
	void		*ptr;
	char		*str_itoa;

	ptr = va_arg(*arg_pf, void *);
	vector = vct_new(flag->width);
	nb_itoa = vct_new(0);
	address = ptr;
	str_itoa = NULL;
	cancel_flag_for_ptr_conv(flag);
	address = (uint64_t*)apply_modifier_p((uint64_t)address, flag->option);
	if ((str_itoa = ft_u_itoa_base((uint64_t)address, 16)) == NULL)
		vct_del(&nb_itoa);
	if (nb_itoa != NULL)
		if ((vct_addstr(nb_itoa, str_itoa)) == FAILURE)
			vct_del(&nb_itoa);
	ft_strdel(&str_itoa);
	if ((apply_prefix(vector, flag, nb_itoa)) == FAILURE)
		vct_del(&vector);
	vct_del(&nb_itoa);
	return (vector);
}
