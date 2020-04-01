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

void		apply_key(t_vector *msg, t_vector *key, t_vector *dest)
{
	size_t		i = 0;
	size_t		j;

	if (msg != NULL && msg->str != NULL)
	{
		dest->len = msg->len;
		while (i < msg->len)
		{
			j = 0;
			while ((j < key->len) && (i + j < msg->len))
			{
				dest->str[i + j] = (msg->str[i + j] ^ key->str[j]);
				j++;
			}
			i += j;
		}
	}
}

void		next_key(t_vector *vector, size_t cycle)
{
	size_t		iteration;
	intmax_t	seed;
	size_t		i;

	iteration = 0;
	while (iteration < cycle)
	{
		seed = ft_seed_string(vector->str, vector->len);
		srand(seed);
		i = 0;
		while (i < vector->len)
		{
			vector->str[i] = (char)rand();
			i++;
		}
		iteration++;
	}
}

t_vector	*feistel(t_crypt *crypto, uint8_t state)
{
	t_vector	*left;
	t_vector	*right;
	t_vector	*cypher;
	t_vector	*tmp;
	t_vector	*key_save;
	size_t		i = 0;

	left = vct_ndup(crypto->msg, crypto->msg->len / 2);
	right = vct_dup_from(crypto->msg, crypto->msg->len / 2);
	//ft_printf("{c_red}");
	//feistel_print_debug("Message", crypto->msg);
	//feistel_print_debug("Left", left);
	//feistel_print_debug("Right", right);
	//feistel_print_debug("Key", crypto->key);
	tmp = vct_new(left->len + 1);
	key_save = vct_dup(crypto->key);
	//ft_printf("{c_magenta}");
	while (i < crypto->nb_cycles)
	{
		if (state == CRYPT)
			next_key(key_save, i);
		else if (state == UNCRYPT)
			next_key(key_save, crypto->nb_cycles - i - 1);
		//feistel_print_debug("0 K", key_save);
		crypto->hash(right, key_save, tmp);
		//feistel_print_debug("1 Right ^ K = tmp", tmp);
		apply_xor(left, tmp);
		//feistel_print_debug("2 Left ^ tmp", left);
		crypto->hash(left, key_save, tmp);
		//feistel_print_debug("3 Left ^ K = tmp", tmp);
		apply_xor(right, tmp);
		//feistel_print_debug("4 Right ^ tmp", right);
		key_save->len = 0;//quick fix
		vct_cat(key_save, crypto->key);
		i++;
	}
	cypher = vct_joinfree(&right, &left, BOTH);
	//feistel_print_debug("Cypher", cypher);
	//ft_printf("{c_end}");
	vct_del(&tmp);
	vct_del(&key_save);
	return (cypher);
}

