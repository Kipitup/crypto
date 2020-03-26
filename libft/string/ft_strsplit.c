/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 10:35:22 by fkante            #+#    #+#             */
/*   Updated: 2020/03/12 14:09:39 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word_count(char const *s, char c)
{
	size_t		count;

	count = 0;
	while (*s != '\0')
	{
		if (*s != c)
			count++;
		while (*s != c && *s != '\0')
			s++;
		while (*s == c && *s != '\0')
			s++;
	}
	return (count);
}

static void		ft_clean(char **tab, size_t i)
{
	while (i > 0)
	{
		i--;
		ft_strdel(&tab[i]);
	}
	free(tab);
}

static char		**ft_fill(char const *s, char c, char **tab, size_t count)
{
	size_t		i;
	ssize_t		j;
	size_t		k;

	i = 0;
	while (i < count)
	{
		j = 0;
		k = 0;
		while (*s == c && *s)
			s++;
		while ((s[j] != c) && s[j])
			j++;
		if (!(tab[i] = (char*)ft_memalloc(sizeof(char) * ((size_t)j + 1))))
		{
			ft_clean(tab, i);
			return (NULL);
		}
		while (--j >= 0)
			tab[i][k++] = (char)*s++;
		tab[i][k] = '\0';
		i++;
	}
	tab[i] = 0;
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	count;

	tab = NULL;
	if (s != NULL)
	{
		count = ft_word_count(s, c);
		tab = (char**)ft_memalloc(sizeof(char *) * (count + 1));
		if (tab != NULL)
			tab = ft_fill(s, c, tab, count);
	}
	return (tab);
}
