/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_to_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 20:31:42 by fkante            #+#    #+#             */
/*   Updated: 2019/10/02 18:30:57 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int8_t		conv_to_r(t_vector *vector, size_t index)
{
	char		*str;
	int8_t		ret;
	int			nb;

	ret = SUCCESS;
	while (index < vct_len(vector))
	{
		if ((ft_isprint(vct_getchar_at(vector, index))) == FALSE)
		{
			nb = (int)vct_getchar_at(vector, index);
			str = ft_itoa_base(nb, 8);
			ret = vct_addchar_at(vector, '\\', index);
			if (ret == FAILURE)
				break ;
			vct_pop_from(vector, 1, index + 1);
			ret = vct_addstr_at(vector, str, index + 1);
			ft_strdel(&str);
			if (ret == FAILURE)
				break ;
			index += ft_int64_t_len(nb, 8) + 1;
		}
		index++;
	}
	return (ret);
}

t_vector	*conv_to_str(va_list *arg_pf, t_flag *flag)
{
	t_vector	*vector;
	t_vector	*to_be_joined;
	char		*str;

	vector = vct_new(flag->width);
	cancel_flag_for_other_conv(flag);
	str = va_arg(*arg_pf, char *);
	str = (char*)apply_modifier_s((uint64_t)str, flag->option);
	if (str == NULL)
		to_be_joined = vct_newstr("(null)");
	else
	{
		to_be_joined = vct_newstr(str);
		if (flag->option & CONV_R)
			if ((conv_to_r(to_be_joined, 0)) == FAILURE)
				vct_del(&to_be_joined);
	}
	if (to_be_joined == NULL)
		vct_del(&vector);
	else if ((apply_padding_flag(vector, flag, to_be_joined)) == FAILURE)
		vct_del(&vector);
	vct_del(&to_be_joined);
	return (vector);
}
