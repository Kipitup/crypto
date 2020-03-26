/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striszero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 11:59:16 by amartino          #+#    #+#             */
/*   Updated: 2019/10/02 12:05:47 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_striszero(char *str)
{
	int		index;

	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] == '0')
			index++;
		else
			return (FALSE);
	}
	return (TRUE);
}
