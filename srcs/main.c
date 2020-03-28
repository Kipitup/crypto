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

void	vct_print_bin_nl(t_vector *vector)
{
	if (vector != NULL && vector->str != NULL)
	{
		ft_printf("%d ", vector->len);
		ft_printf("[%*s]\t", vector->len, vector->str);
		ft_printf("%b\n", 2, vector->str, 2);
	}
}

void	feistel_print_debug(t_vector *left, t_vector *right)
{
	ft_printf("Left : ");
	vct_print_bin_nl(left);
	ft_printf("Right: ");
	vct_print_bin_nl(right);
}

t_vector	*feistel(t_crypt *crypto)
{
	t_vector	*left;
	t_vector	*right;
	t_vector	*cypher;
	size_t		i = 0;

	left = vct_ndup(crypto->msg, crypto->msg->len / 2);
	right = vct_dup_from(crypto->msg, crypto->msg->len / 2);
	feistel_print_debug(left, right);
	while (i < crypto->nb_cycles)
	{
		crypto->hash(right, crypto->key);
		apply_xor(left, right);
		feistel_print_debug(left, right);
		crypto->hash(left, crypto->key);
		apply_xor(right, left);
		feistel_print_debug(right, left);
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
	ft_printf("message %d : [%s]\n", crypto->msg->len, crypto->msg->str);
	ft_printf("key %d : [%s]\n", crypto->key->len, crypto->key->str);
	ft_printf("cypher %d : [%s]\n", crypto->cypher->len, crypto->cypher->str);
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
			crypto->msg = crypto->cypher;
			crypto->cypher = feistel(crypto);
			print_crypt(crypto);
		}
		clean_feistel(&crypto);
	}
	return (0);
}
