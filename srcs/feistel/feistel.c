#include "head.h"

static void		handle_unbalanced_feistel_cypher(t_crypt *crypto)
{
	if (crypto->state == CRYPT)
		vct_addchar(crypto->cypher, '\0');
	else
		vct_pop(crypto->cypher, 1);
}

static int8_t	feistel_cycle(t_crypt *crypto, t_vector *left, t_vector *right,
		t_vector *hash_output, t_vector *sub_key)
{
	size_t		cycles;
	size_t		i = 0;

	cycles = crypto->nb_cycles * 2;
	while (i < cycles)
	{
		if (crypto->state == CRYPT)
			next_key(sub_key, i);
		else if (crypto->state == DECRYPT)
			next_key(sub_key, cycles - i - 1);

		crypto->hash(right, sub_key, hash_output);
		apply_xor(left, hash_output);
		vct_swap_ptr(&left, &right);
		vct_copy(sub_key, crypto->key);
		i++;
	}
	return (SUCCESS);
}

t_vector		*feistel(t_crypt *crypto)
{
	t_vector	*left;
	t_vector	*right;
	t_vector	*cypher;
	t_vector	*hash_output;
	t_vector	*sub_key;

	cypher = NULL;
	left = vct_ndup(crypto->msg, crypto->msg->len / 2);
	right = vct_dup_from(crypto->msg, crypto->msg->len / 2);
	hash_output = vct_new(right->len + 1);
	sub_key = vct_dup(crypto->key);
	if (left != NULL && right != NULL && hash_output != NULL && sub_key != NULL)
	{
		if (feistel_cycle(crypto, left, right, hash_output, sub_key) == FAILURE)
		{
			vct_del(&left);
			vct_del(&right);
		}
		cypher = vct_joinfree(&right, &left, BOTH);
	}
	vct_del(&hash_output);
	vct_del(&sub_key);
	return (cypher);
}

t_crypt			*feistel_cypher(char *msg, char *key, t_feistel_hash hash_func,
		size_t cycles, char *str_state)
{
	t_crypt		*crypto;

	crypto = init(msg, key, hash_func, cycles, str_state);
	if (crypto != NULL)
	{
		crypto->cypher = feistel(crypto);
		if (crypto->is_balanced == FALSE)
			handle_unbalanced_feistel_cypher(crypto);
	}
	return (crypto);
}
