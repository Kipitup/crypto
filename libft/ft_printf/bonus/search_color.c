/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 01:26:56 by amartino          #+#    #+#             */
/*   Updated: 2020/01/15 12:14:08 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		search_color(t_state_machine *ptf, t_vector *vector,
							char *input, int i)
{
	char		*str;
	ssize_t		index;
	ssize_t		len;

	if ((str = ft_strndup(input, i)) == NULL)
	{
		ptf->state = ST_ERROR;
		return ;
	}
	index = vct_chr_str(vector, str);
	ft_strdel(&str);
	if (index == FAILURE)
		return ;
	index += i;
	len = (index + 4 == (ssize_t)vct_len(vector)) ? 4 : 7;
	while (len > 0)
	{
		if ((vct_addchar(ptf->output, vct_getchar_at(vector, index))) == -1)
		{
			ptf->state = ST_ERROR;
			break ;
		}
		index++;
		len--;
	}
}
