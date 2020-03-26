/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 15:42:12 by amartino          #+#    #+#             */
/*   Updated: 2019/09/20 09:53:31 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int8_t	convert(t_state_machine *ptf, t_flag *flag, char *input,
		va_list *arg_pf)
{
	static t_convfunc	func_ptr[NB_OF_CONVS] = {conv_to_c, conv_to_str,
							conv_to_ptr, conv_to_di, conv_to_di, conv_to_ox,
							conv_to_u, conv_to_ox, conv_to_hexa_maj, conv_to_f,
							conv_to_str, conv_to_b};
	t_vector			*local;
	uint8_t				i;

	i = -1;
	local = NULL;
	while (++i < NB_OF_CONVS)
	{
		if (ptf->option & ((1 << i) << SHIFT_TO_CONVS))
		{
			if ((local = func_ptr[i](arg_pf, flag)) == NULL)
				return (FAILURE);
			break ;
		}
	}
	if (i == NB_OF_CONVS && (ptf->option & ((1 << i) << SHIFT_TO_CONVS)))
		if ((local = conv_to_none(*input, flag)) == NULL)
			return (FAILURE);
	if (local == NULL || (vct_cat(ptf->output, local) == FAILURE))
		return (FAILURE);
	vct_del(&local);
	return (SUCCESS);
}
