/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fldtoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 15:50:31 by fkante            #+#    #+#             */
/*   Updated: 2020/04/01 16:48:48 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "libft.h"
#include "define_pf.h"

static int8_t		round_up_ld(t_vector *vector, uint64_t accuracy)
{
	char	c;

	c = vct_getchar_at(vector, accuracy);
	if (c >= '0' && c <= '9')
		vct_replace_char_at(vector, accuracy, c + 1);
	if (c == '9' || c == '.')
	{
		if ((round_up_ld(vector, accuracy - 1)) == SUCCESS)
		{
			if (c == '.')
				return (SUCCESS);
			else
				vct_replace_char_at(vector, accuracy, '0');
		}
	}
	return (SUCCESS);
}

static int8_t		check_for_rounding_up_ld(t_vector *vector, double value)
{
	int64_t		cast;
	uint64_t	accuracy;

	value *= 10;
	cast = (int64_t)value;
	accuracy = (uint64_t)vct_len(vector) - 1;
	if (cast > 4)
		if ((round_up_ld(vector, accuracy)) == FAILURE)
			vct_del(&vector);
	return (vector == NULL ? FAILURE : SUCCESS);
}

static int8_t		nb_to_string_ld(t_vector *vector, double value, uint64_t accuracy)
{
	const char	*base_str;
	uint64_t	i;
	int64_t		cast;

	base_str = "0123456789";
	i = accuracy;
	while (i > 0 && vector != NULL)
	{
		value *= 10;
		cast = (int64_t)value;
		value -= (long double)cast;
		if ((vct_addchar(vector, base_str[cast % 10])) == FAILURE)
			vct_del(&vector);
		i--;
	}
	if ((check_for_rounding_up_ld(vector, value)) == FAILURE)
		vct_del(&vector);
	return (vector == NULL ? FAILURE : SUCCESS);
}

t_vector			*ft_fldtoa(long double value, uint64_t precision, uint32_t option)
{
	t_vector	*vector;
	char		*str;
	int64_t		cast;
	uint64_t	accuracy;

	vector = vct_new(0);
	if (vector != NULL)
	{
		if ((str = ft_d_itoa(value)) != NULL)
			if ((vct_addstr(vector, str)) == FAILURE)
				vct_del(&vector);
		ft_strdel(&str);
		cast = (int64_t)value;
		value -= (long double)cast;
		value = value < 0 ? -value : value;
		accuracy = (option & FLAG_POINT) ? precision : 6;
		if (accuracy > 0)
			if ((vct_addchar(vector, '.')) == FAILURE)
				vct_del(&vector);
		if (vector != NULL)
			if ((nb_to_string_ld(vector, value, accuracy)) == FAILURE)
				vct_del(&vector);
	}
	return (vector);
}
