/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezalos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 17:51:29 by ezalos            #+#    #+#             */
/*   Updated: 2020/03/26 19:47:17 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

t_vector	*feistel(t_crypt *crypto)
{
	t_vector	*cypher;


	return (cypher);
}

void		rot(t_vector *vct, int rot)
{
	size_t		i;

	i = 0;
	if (vct != NULL && vct->str != NULL)
	{
		while (i < vct->len)
		{
			vct->str[i] = (vct->str[i] + rot) % 256;
			i++;
		}
	}
}

t_crypt		*init(char *msg, char *key, t_feistel_hash hash_func)
{
	t_crypt		*crypto;

	crypto = ft_memalloc(sizeof(t_crypt));
	if (crypto != NULL)
	{
		crypto->msg = vct_newstr(msg);
		crypto->key = vct_newstr(key);
		crypto->hash = hash_func;
		if (vct_len(crypto->msg) % 2 == 1)
			vct_addchar(crypto->msg, '\0');
		if (crypto->msg == NULL || crypto->key == NULL)
			clean_feistel(&crypto);
	}
	return (crypto);
}

int		main(int ac, char **av)
{
	t_crypt		*crypto;
	t_vector	*cypher;

	if (ac > 2)
	{
		crypto = init(av[1], av[2], NULL);
		if (crypto != NULL)
		{
			cypher = feistel(crypto);
			ft_printf("message : %s\nkey: %s\ncypher: %s\n", crypto->msg->str, crypto->key->str, cypher->str);
		}
		clean_feistel(&crypto);
	}
	return (0);
}
