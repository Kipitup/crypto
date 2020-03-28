#include "head.h"

static void		apply_xor(t_vector *left, t_vector *right)
{
	size_t	i = 0;

	while (i < left->len)
	{
		left->str[i] ^= right->str[i];
		i++;
	}
}

void		apply_key(t_vector *msg, t_vector *key)
{
	size_t		i = 0;
	size_t		j;

	if (msg != NULL && msg->str != NULL)
	{
		while (i < msg->len)
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
	t_vector	*left;
	t_vector	*right;
	t_vector	*cypher;
	size_t		i = 0;

	left = vct_ndup(crypto->msg, crypto->msg->len / 2);
	right = vct_dup_from(crypto->msg, crypto->msg->len / 2);
	while (i < crypto->nb_cycles)
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

static t_crypt		*init(char *msg, char *key, t_feistel_hash hash_func)
{
	t_crypt		*crypto;

	crypto = ft_memalloc(sizeof(t_crypt));
	if (crypto != NULL)
	{
		crypto->msg = vct_newstr(msg);
		crypto->key = vct_newstr(key);
		crypto->hash = hash_func;
		crypto->nb_cycles = FEISTEL_CYCLES;
		if (vct_len(crypto->msg) % 2 == 1)
			vct_addchar(crypto->msg, '\0');
		if (crypto->msg == NULL || crypto->key == NULL)
			clean_feistel(&crypto);
	}
	return (crypto);
}

void	print_crypt(t_crypt *crypto)
{
	ft_printf("message : %s\n", crypto->msg->str);
	ft_printf("key: [%s]\n", crypto->key->str);
	ft_printf("cypher: [%s]\n", crypto->cypher->str);
}

int		main(int ac, char **av)
{
	t_crypt		*crypto;

	if (ac > 2)
	{
		crypto = init(av[1], av[2], &apply_key);
		if (crypto != NULL)
		{
			crypto->cypher = feistel(crypto);
			print_crypt(crypto);
		}
		clean_feistel(&crypto);
	}
	return (0);
}
