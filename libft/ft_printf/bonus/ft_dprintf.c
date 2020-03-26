/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 16:01:21 by amartino          #+#    #+#             */
/*   Updated: 2019/09/19 16:06:21 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_dprintf(int fd, const char *input, ...)
{
	t_state_machine		ptf;
	va_list				arg_pf;
	ssize_t				ret;

	ret = init_state_machine(&ptf, fd);
	if (ret == SUCCESS)
	{
		va_start(arg_pf, input);
		ret = parser(&ptf, (char *)input, &arg_pf);
		vct_del(&(ptf.output));
		va_end(arg_pf);
	}
	return (ret);
}
