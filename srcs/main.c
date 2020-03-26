/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezalos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 17:51:29 by ezalos            #+#    #+#             */
/*   Updated: 2020/03/26 20:33:39 by ezalos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void		apply_xor(t_vector *left, t_vector *right)
{
	size_t	i = 0;

	while (i < left->len)
	{
		left->str[i] ^= right->str[i];
		i++;
	}
}

void		apply_key(t_vector *msg, t_vector *key,int rot)
{
	size_t		i = 0;
	size_t		j;

	if (msg != NULL && msg->str != NULL)
	{
		while (i + j < msg->len)
		{
			j = 0;
			while (j < key->len)
			{
				msg->str[i + j] = (msg->str[i + j] ^ key->str[j]);
				j++;
			}
			i += j;
		}
	}
}

t_vector	*feistel(t_crypt *crypto)
{
	t_vector	*left = NULL;
	t_vector	*right = NULL;
	size_t		i = 0;

	left = vct_ndup(crypto->msg, crypto->msg->len / 2);
	right = vct_dup_from(crypto->msg, crypto->msg->len / 2);
	while (i < crypto->cycles)
	{
		crypto->hash(right, crypto->key);
		apply_xor(left, right);
		crypto->hash(left, crypto->key);
		apply_xor(right, left);
		i++;
	}
	cypher = vct_joinfree(&right, &left, BOTH);
	return (cypher);
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
		crypto->cycles = FEISTEL_CYCLES;
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
		crypto = init(av[1], av[2], &apply_key());
		if (crypto != NULL)
		{
			cypher = feistel(crypto);
			ft_printf("message : %s\nkey: %s\ncypher: %s\n", crypto->msg->str, crypto->key->str, cypher->str);
		}
		clean_feistel(&crypto);
	}
	return (0);
}
