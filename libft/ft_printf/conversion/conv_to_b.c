/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 09:26:27 by fkante            #+#    #+#             */
/*   Updated: 2020/03/28 18:58:21 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void		add_padding_for_base_2(t_vector *nb)
{
	size_t	i;

	i = 8;
	while (i < nb->len)
	{
		vct_addchar_at(nb, ' ', i);
		i += 8;
	}
	if (nb->len % 8 != 0)
		vct_fill_before(nb, '0', (8 - (nb->len % 8)));
}

int8_t			conv_b(t_vector *vector, t_flag *flag, t_vector *nb_itoa)
{
	int	ret;

	ret = FAILURE;
	if (vector != NULL && nb_itoa != NULL)
		ret = apply_padding_flag(vector, flag, nb_itoa);
	return (ret);
}

t_vector		*conv_to_b(va_list *arg_pf, t_flag *flag)
{
	t_vector	*vector;
	t_vector	*nb_itoa;
	char		*str_itoa;
	uint64_t	nbr;
	size_t		base;

	base = va_arg(*arg_pf, int);
	if (base == 1 || base == 0)
		return (NULL);
	nbr = va_arg(*arg_pf, uint64_t);
	vector = vct_new(flag->width);
	nb_itoa = vct_new(0);
	cancel_flag_for_numeric_conv(flag);
	if ((str_itoa = ft_ox_itoa_base(nbr, base, flag->option)) == NULL)
		vct_del(&nb_itoa);
	if (nb_itoa != NULL)
		if ((vct_addstr(nb_itoa, str_itoa)) == FAILURE)
			vct_del(&nb_itoa);
	ft_strdel(&str_itoa);
	if (base == 2 && nb_itoa != NULL)
		add_padding_for_base_2(nb_itoa);
	if ((conv_b(vector, flag, nb_itoa)) == FAILURE)
		vct_del(&vector);
	vct_del(&nb_itoa);
	return (vector);
}
