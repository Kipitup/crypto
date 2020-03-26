/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:44:43 by fkante            #+#    #+#             */
/*   Updated: 2019/04/26 08:47:43 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	size_t	size;
	size_t	end;
	char	*trim_new;

	if (s == NULL)
		return (NULL);
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	if (*s == '\0')
		return (ft_memalloc(1));
	end = 0;
	size = ft_strlen(s);
	while (s[size - end - 1] == ' ' || s[size - end - 1] == '\n'
			|| s[size - end - 1] == '\t')
		end++;
	if (!(trim_new = ft_strsub(s, 0, size - end)))
		return (NULL);
	return (trim_new);
}
