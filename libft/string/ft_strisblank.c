/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisblank.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 13:34:41 by amartino          #+#    #+#             */
/*   Updated: 2019/09/13 13:58:35 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strisblank(char *str)
{
	int		index;

	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] == ' ' || str[index] == '\t' || str[index] == '\n')
			index++;
		else
			return (FALSE);
	}
	return (TRUE);
}
