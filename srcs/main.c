#include "head.h"

int		main(int ac, char **av)
{
	t_crypt		*crypto;

	if (ac > 2)
	{
		crypto = init(av[1], av[2], &apply_key);
		if (crypto != NULL)
		{
			crypto->cypher = feistel(crypto, CRYPT);
			print_crypt(crypto);
			ft_printf("\n\n\n");
			crypto->msg = crypto->cypher;
			crypto->cypher = feistel(crypto, UNCRYPT);
			print_crypt(crypto);
		}
		clean_feistel(&crypto);
	}
	return (0);
}
