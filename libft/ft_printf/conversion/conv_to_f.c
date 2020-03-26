/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_to_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 09:11:36 by fkante            #+#    #+#             */
/*   Updated: 2020/02/28 16:30:41 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int8_t			conv_f(t_vector *vector, t_flag *flag, t_vector *nb_ftoa)
{
	int	ret;

	ret = FAILURE;
	if (vector != NULL && nb_ftoa != NULL)
	{
		if (vct_chr_str(nb_ftoa, NAN_STR) == SUCCESS)
		{
			flag->option &= ~FLAG_NAN;
			flag->precision = 0;
		}
		if (vct_chr_str(nb_ftoa, MINUS_INF_STR) == SUCCESS
				|| vct_chr_str(nb_ftoa, INF_STR) == SUCCESS)
		{
			flag->option &= ~FLAG_INF;
			flag->precision = 0;
		}
		ret = apply_padding_flag(vector, flag, nb_ftoa);
		if (ret == SUCCESS)
			ret = apply_hash_float(vector, flag);
	}
	return (ret);
}

t_vector		*get_float(double nbr, t_flag *flag)
{
	t_vector	*nb_ftoa;

	if (nbr != nbr)
		nb_ftoa = vct_newstr(NAN_STR);
	else if (nbr * 2 == nbr && nbr < 0)
		nb_ftoa = vct_newstr(MINUS_INF_STR);
	else if (nbr * 2 == nbr && nbr > 0)
		nb_ftoa = vct_newstr(INF_STR);
	else
	{
		if (nbr < (double)LLONG_MIN || nbr > (double)LLONG_MAX)
			return (NULL);
		nb_ftoa = ft_ftoa(nbr, flag->precision, flag->option);
	}
	return (nb_ftoa);
}

t_vector		*get_d_float(long double ldb, t_flag *flag)
{
	t_vector	*nb_ftoa;

	if (ldb != ldb)
		nb_ftoa = vct_newstr(NAN_STR);
	else if (ldb * 2 == ldb && ldb < 0)
		nb_ftoa = vct_newstr(MINUS_INF_STR);
	else if (ldb * 2 == ldb && ldb > 0)
		nb_ftoa = vct_newstr(INF_STR);
	else
	{
		if (ldb < (long double)LLONG_MIN || ldb > (long double)LLONG_MAX)
			return (NULL);
		nb_ftoa = ft_fldtoa(ldb, flag->precision, flag->option);
	}
	return (nb_ftoa);
}

t_vector		*conv_to_f(va_list *arg_pf, t_flag *flag)
{
	t_vector	*vector;
	t_vector	*nb_ftoa;
	long double	ldb;
	double		nbr;

	nb_ftoa = NULL;
	if (flag->option & FLAG_L_MAJ)
	{
		ldb = va_arg(*arg_pf, long double);
		nb_ftoa = get_d_float(ldb, flag);
	}
	else
	{
		nbr = va_arg(*arg_pf, double);
		nb_ftoa = get_float(nbr, flag);
	}
	vector = vct_new(flag->width);
	if ((conv_f(vector, flag, nb_ftoa)) == FAILURE)
		vct_del(&vector);
	vct_del(&nb_ftoa);
	return (vector);
}
