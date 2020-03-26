/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 17:12:35 by amartino          #+#    #+#             */
/*   Updated: 2019/09/20 02:49:58 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf(const char *input, ...)
{
	t_state_machine		ptf;
	va_list				arg_pf;
	ssize_t				ret;

	ret = init_state_machine(&ptf, STD_OUT);
	if (ret == SUCCESS)
	{
		va_start(arg_pf, input);
		ret = parser(&ptf, (char *)input, &arg_pf);
		vct_del(&(ptf.output));
		va_end(arg_pf);
	}
	return (ret);
}
