#include "head.h"

static uint8_t	is_msg_len_even(t_crypt *crypto)
{
	if (crypto != NULL && crypto->msg != NULL)
	{
		if (vct_len(crypto->msg) % 2 != 0)
		{
			if (crypto->state == CRYPT)
				vct_addchar(crypto->msg, '\0');
			else if (crypto->state == DECRYPT)
				vct_pop(crypto->msg, 1);
			return (FALSE);
		}
	}
	return (TRUE);
}

t_crypt			*init(char *msg, char *key, t_feistel_hash hash_func,
		size_t cycles, char *str_state)
{
	t_crypt		*crypto;

	crypto = NULL;
	if (msg != NULL && key != NULL && hash_func != NULL && str_state !=  NULL)
	{
		crypto = ft_memalloc(sizeof(t_crypt));
		if (crypto != NULL)
		{
			crypto->msg = get_arg(msg);
			crypto->key = get_arg(key);
			crypto->hash = hash_func;
			crypto->nb_cycles = cycles;
			crypto->state = get_state(str_state);
			crypto->is_balanced = is_msg_len_even(crypto);
			if (crypto->state == FAILURE)
				ft_dprintf(STD_ERR, "Usage: state is either CRYPT or DECRYPT\n");
			if (crypto->msg == NULL || crypto->key == NULL || crypto->state == FAILURE)
				clean_feistel(&crypto);
		}
	}
	else
		ft_dprintf(STD_ERR, "Usage: msg_to_crypt key nb_of_cycle [CRYPT / DECRYPT]\n");
	return (crypto);
}
