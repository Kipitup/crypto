#include "head.h"

int		main(int ac, char **av)
{
	t_crypt		*crypto;

	if (ac > 4)
	{
		crypto = feistel_cypher(av[1], av[2], &apply_key, ft_atoi(av[3]), av[4]);
		if (crypto != NULL)
			vct_dprint(STD_OUT, crypto->cypher);
		clean_feistel(&crypto);
	}
	else
		ft_printf("Usage: %s to_crypt key [CRYPT / DECRYPT]\n", av[0]);
	return (EXIT_SUCCESS);
}
