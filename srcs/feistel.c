#include "head.h"

static void		apply_xor(t_vector *left, t_vector *hash_output)
{
	size_t	i = 0;

	while (i < left->len)
	{
		left->str[i] ^= hash_output->str[i];
		i++;
	}
}

void			next_key(t_vector *sub_key, size_t cycle)
{
	size_t		iteration;
	intmax_t	seed;
	size_t		i;

	iteration = 0;
	if (sub_key == NULL)
		return ;
	while (iteration < cycle)
	{
		i = 0;
		seed = ft_seed_string(sub_key->str, sub_key->len);
		srand(seed);
		while (i < sub_key->len)
		{
			vct_replace_char_at(sub_key, i, (char)rand());
			i++;
		}
		iteration++;
	}
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
		else if (crypto->state == UNCRYPT)
			next_key(sub_key, cycles - i - 1);
		
		crypto->hash(right, sub_key, hash_output);
		apply_xor(left, hash_output);

//		print_feistel_cycle(sub_key, hash_output, left, i);

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
		//ft_dprintf(STD_ERR, "{c_red}");
		//feistel_print_debug("Message", crypto->msg);
		//feistel_print_debug("Left", left);
		//feistel_print_debug("Right", right);
		//feistel_print_debug("Key", crypto->key);
		if (feistel_cycle(crypto, left, right, hash_output, sub_key) == FAILURE)
		{
			vct_del(&left);
			vct_del(&right);
		}
		cypher = vct_joinfree(&right, &left, BOTH);
//		if (crypto->state == CRYPT)
//			ft_dprintf(STD_ERR, "{c_blue}");
//		else
//			ft_dprintf(STD_ERR, "{c_cyan}");
//		ft_dprintf(STD_ERR, "len  %zu\nsize %zu\n", cypher->len, cypher->size);
//		write(2, cypher->str, cypher->len);
//		ft_dprintf(STD_ERR, "{c_end}\n");
//		feistel_print_debug("Cypher", cypher);
		//ft_dprintf(STD_ERR, "{c_end}");
	}
	vct_del(&hash_output);
	vct_del(&sub_key);
	return (cypher);
}



//	while (i < crypto->nb_cycles)
//	{
//		if (crypto->state == CRYPT)
//			next_key(sub_key, i);
//		else if (crypto->state == UNCRYPT)
//			next_key(sub_key, crypto->nb_cycles - i - 1);
//		feistel_print_debug("0 K", sub_key);
//		
//		crypto->hash(right, sub_key, hash_output);
//		feistel_print_debug("1 Right ^ K = hash_output", hash_output);
//		
//		apply_xor(left, hash_output);
//		feistel_print_debug("2 Left ^ hash_output", left);
//		
//		crypto->hash(left, sub_key, hash_output);
//		feistel_print_debug("3 Left ^ K = hash_output", hash_output);
//		
//		apply_xor(right, hash_output);
//		feistel_print_debug("4 Right ^ hash_output", right);
//		
//		vct_copy(sub_key, crypto->key);
//		i++;
//	}
//
