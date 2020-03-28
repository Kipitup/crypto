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

t_vector	*feistel(t_crypt *crypto)
{
	t_vector	*left;
	t_vector	*right;
	t_vector	*cypher;
	t_vector	*tmp;
	size_t		i = 0;

	left = vct_ndup(crypto->msg, crypto->msg->len / 2);
	right = vct_dup_from(crypto->msg, crypto->msg->len / 2);
	ft_printf("{c_red}");
	feistel_print_debug("Message", crypto->msg);
	feistel_print_debug("Left", left);
	feistel_print_debug("Right", right);
	feistel_print_debug("Key", crypto->key);
	tmp = vct_new(left->len + 1);
	while (i < crypto->nb_cycles)
	{
		crypto->hash(right, crypto->key, tmp);
		ft_printf("{c_magenta}");
		feistel_print_debug("1 Right ^ K", tmp);
		apply_xor(left, tmp);
		feistel_print_debug("2 Left ^ R", left);
		crypto->hash(left, crypto->key, tmp);
		feistel_print_debug("3 Left ^ K", tmp);
		apply_xor(right, tmp);
		feistel_print_debug("4 Right ^ L", right);
		i++;
	}
	cypher = vct_joinfree(&right, &left, BOTH);
	feistel_print_debug("Cypher", cypher);
	ft_printf("{c_end}");
	vct_del(&tmp);
	return (cypher);
}
