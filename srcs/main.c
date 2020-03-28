#include "head.h"
#define MAX_LEN_PRINT 12

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
	size_t		i;

	if (vector != NULL && vector->str != NULL)
	{
		ft_printf("%d ", vector->len);
		ft_printf("[");
		vct_print(vector);
		ft_printf("]");
		i = 0;
		while (i < MAX_LEN_PRINT - vector->len)
		{
			ft_printf(" ");
			i++;
		}
		ft_printf("\t");
		i = 0;
		while (i < vector->len)
		{
			ft_printf("%0b ", 2, vector->str[i++]);
		}
		ft_printf("\n");
	}
}

void	feistel_print_debug(char *name, t_vector *vct)
{
	ft_printf("%-*s : ", MAX_LEN_PRINT, name);
	vct_print_bin_nl(vct);
}

t_vector	*feistel(t_crypt *crypto)
{
	t_vector	*left;
	t_vector	*right;
	t_vector	*cypher;
	size_t		i = 0;

	left = vct_ndup(crypto->msg, crypto->msg->len / 2);
	right = vct_dup_from(crypto->msg, crypto->msg->len / 2);
	feistel_print_debug("Message", crypto->msg);
	feistel_print_debug("Left", left);
	feistel_print_debug("Right", right);
	feistel_print_debug("Key", crypto->key);
	while (i < crypto->nb_cycles)
	{
		crypto->hash(right, crypto->key);
		feistel_print_debug("1 Right ^ K", right);
		apply_xor(left, right);
		feistel_print_debug("2 Left ^ R", left);
		crypto->hash(left, crypto->key);
		feistel_print_debug("3 Left ^ K", left);
		apply_xor(right, left);
		feistel_print_debug("4 Right ^ L", right);
		i++;
	}
	cypher = vct_joinfree(&right, &left, BOTH);
	feistel_print_debug("Cypher", cypher);
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
	feistel_print_debug("message", crypto->msg);
	feistel_print_debug("key", crypto->key);
	feistel_print_debug("cypher", crypto->cypher);
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
