/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_padding_flag.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 17:05:02 by amartino          #+#    #+#             */
/*   Updated: 2019/10/02 12:11:37 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int8_t		apply_padding_flag(t_vector *vector, t_flag *flag, t_vector *nb_ito)
{
	t_vector	*sign;
	int8_t		ret;

	sign = handle_sign(nb_ito, flag);
	ret = sign == NULL ? FAILURE : SUCCESS;
	if (ret == SUCCESS)
		ret = vct_cat(vector, nb_ito);
	if (ret == SUCCESS)
		ret = apply_precision(vector, flag);
	if (ret == SUCCESS)
		ret = apply_hash(vector, flag);
	if (sign != NULL && vct_len(sign) > 0
			&& ((flag->option & FLAG_ZERO) == FALSE))
		ret = vct_addchar_at(vector, vct_getchar_at(sign, START), START);
	if (ret == SUCCESS)
		ret = apply_width(vector, flag);
	if (sign != NULL && vct_len(sign) > 0 && flag->option & FLAG_ZERO)
	{
		if (vct_getchar_at(vector, START) == '0')
			vct_pop_from(vector, 1, 0);
		ret = vct_addchar_at(vector, vct_getchar_at(sign, START), START);
	}
	vct_del(&sign);
	return (ret);
}

t_vector	*handle_sign(t_vector *nb_itoa, t_flag *flag)
{
	t_vector	*sign;

	sign = vct_new(0);
	if (nb_itoa->str[0] == '-')
	{
		vct_addchar(sign, '-');
		vct_pop_from(nb_itoa, 1, 0);
	}
	else if (flag->option & FLAG_PLUS)
		vct_addchar(sign, '+');
	else if (flag->option & FLAG_SPACE)
		vct_addchar(sign, ' ');
	return (sign);
}

int8_t		apply_precision(t_vector *vector, t_flag *flag)
{
	uint64_t	len;
	int8_t		ret;

	ret = SUCCESS;
	if ((flag->option & CONV_S) && (flag->option & FLAG_POINT))
	{
		if (flag->precision < vct_len(vector))
			vct_pop(vector, (vct_len(vector) - (size_t)flag->precision));
	}
	else if ((flag->option & CONV_C) == FALSE)
	{
		if (flag->precision >= vct_len(vector))
		{
			len = flag->precision - vct_len(vector);
			if (flag->option & FLAG_POINT)
				ret = vct_fill_before(vector, '0', len);
		}
		else
			apply_hash_special_case(vector, flag);
	}
	return (ret);
}

int8_t		apply_width(t_vector *vector, t_flag *flag)
{
	uint64_t	len;
	int8_t		ret;

	ret = SUCCESS;
	len = flag->width < vct_len(vector) ? 0 : flag->width - vct_len(vector);
	if (len > 0)
	{
		if (flag->option & FLAG_MINUS)
			ret = vct_fill_after(vector, ' ', len);
		else if (flag->option & FLAG_ZERO)
		{
			ret = vct_fill_before(vector, '0', len);
			if (flag->option & CONV_X || flag->option & CONV_X_MAJ)
			{
				if (ret == SUCCESS)
					apply_hash_flag_zero(vector, flag);
			}
		}
		else
			ret = vct_fill_before(vector, ' ', len);
	}
	return (ret);
}
