#include "head.h"

void		get_message_and_key(t_crypt *crypto, char *msg, char *key)
{
	t_vector	*file;
	int			fd;
	
	fd = open(msg, O_RDWR, 744);
	if (fd != FAILURE)
	{
		file = ft_get_file(fd);
		crypto->msg = file;
	}
	else
		crypto->msg = vct_newstr(msg);

	fd = open(key, O_RDWR, 744);
	if (fd != FAILURE)
	{
		file = ft_get_file(fd);
		crypto->key = file;
	}
	else
		crypto->key = vct_newstr(key);
}

t_crypt		*init(char *msg, char *key, t_feistel_hash hash_func, size_t cycles)
{
	t_crypt		*crypto;

	crypto = ft_memalloc(sizeof(t_crypt));
	if (crypto != NULL)
	{
		get_message_and_key(crypto, msg, key);
		crypto->hash = hash_func;
		crypto->nb_cycles = cycles;
		if (vct_len(crypto->msg) % 2 == 1)
			vct_addchar(crypto->msg, '\0');
		if (crypto->msg == NULL || crypto->key == NULL)
			clean_feistel(&crypto);
	}
	return (crypto);
}
